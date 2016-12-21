/*
Top module is modeled as the basys board itself to
be more intuitive.
*/
`timescale 1ns / 1ps

module timer (
        // input [15:0] swt,   //basys board switches
        input clk,          //basys board clock
        // input btnU,         //up button on basys board
        // input btnD,         //up button on basys board
        // input btnL,         //up button on basys board
        // input btnR,         //up button on basys board
        input btnC,         //up button on basys board
        output [3:0] segEn, //basys seven segment enable bus
        // output segDec,         //seven segment decimal point
        output [6:0] seg,   //seven segment signals
        output [14:0] led   //basys board LED array
    );

    wire reset;
    debounce resetBtn(.Clk(clk), .PB(btnC), .pulse(reset));

    reg [3:0] dispD3 = 0, dispD2 = 0, dispD1 = 0, dispD0 = 0;
    SevSegDriver display(
            .clk(clk),
            .rst(reset),
            .disp3(dispD3),
            .disp2(dispD2),
            .disp1(dispD1),
            .disp0(dispD0),
            .segEn(segEn),
            .seg(seg)
        );

        reg [31:0] secCount = 0;
        reg secSig = 0, tenthSig = 0, minuteOneSig = 0, minuteTenthSig = 0;
        always @(posedge clk or posedge reset) begin
            if(reset) begin
                secSig <= 1'b0;
                secCount <= 32'd0;
            end
            else if(secCount == 32'd100000000) begin
                secCount <= 32'd0;
                secSig <= 1'b1;
            end
            else begin
                secSig <= 1'b0;
                secCount <= secCount + 1;
            end
        end

        always @ ( posedge secSig, posedge reset ) begin
            if(reset) begin
                dispD0 <= 4'd0;
                tenthSig <= 1'b0;
            end
            else if(dispD0 == 4'd9) begin
                dispD0 <= 4'd0;
                tenthSig <= 1'b1;
            end
            else begin
                dispD0 <= dispD0 + 1;
                tenthSig <= 1'b0;
            end
        end

        always @ ( posedge tenthSig, posedge reset ) begin
            if(reset) begin
                dispD1 <= 0;
                minuteOneSig <= 0;
            end
            else if((dispD1 == 4'd5) && (dispD0 == 4'd9)) begin
                dispD1 <= 0;
                minuteOneSig <= 1;
            end
            else begin
                dispD1 <= dispD1 + 1;
                minuteOneSig <= 0;
            end
        end

        always @ ( posedge minuteOneSig, posedge reset ) begin
            if(reset) begin
                dispD2 <= 0;
                minuteTenthSig <= 0;
            end
            else if(dispD2 == 4'd9) begin
                dispD2 <= 0;
                minuteTenthSig <= 1;
            end
            else begin
                dispD2 <= dispD2 + 1;
                minuteTenthSig <= 0;
            end
        end

        reg [3:0] hourCount = 0;
        bcdTo1Hot hoursDisplay(hourCount, led);
        always @ ( posedge minuteTenthSig, posedge reset ) begin
            if(reset) begin
                dispD3 <= 0;
                hourCount <= 0;
            end
            else if((dispD3 == 4'd5) && (dispD2 == 4'd9)) begin
                dispD3 <= 0;
                hourCount <= hourCount + 1;
            end
            else begin
                dispD3 <= dispD3 + 1;
                hourCount <= hourCount;
            end
        end

endmodule
