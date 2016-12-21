`timescale 1ns / 1ps

module bcdTo1Hot (
        input [3:0] bcdNum,
        output [14:0] led
    );

    assign led = (bcdNum == 4'd1) ? 15'b000000000000001 :
                 (bcdNum == 4'd2) ? 15'b000000000000010 :
                 (bcdNum == 4'd3) ? 15'b000000000000100 :
                 (bcdNum == 4'd4) ? 15'b000000000001000 :
                 (bcdNum == 4'd5) ? 15'b000000000010000 :
                 (bcdNum == 4'd6) ? 15'b000000000100000 :
                 (bcdNum == 4'd7) ? 15'b000000001000000 :
                 (bcdNum == 4'd8) ? 15'b000000010000000 :
                 (bcdNum == 4'd9) ? 15'b000000100000000 :
                 (bcdNum == 4'd10)? 15'b000001000000000 :
                 (bcdNum == 4'd11)? 15'b000010000000000 :
                 (bcdNum == 4'd12)? 15'b000100000000000 :
                 (bcdNum == 4'd13)? 15'b001000000000000 :
                 (bcdNum == 4'd14)? 15'b010000000000000 :
                 (bcdNum == 4'd15)? 15'b100000000000000 :
                                    15'b000000000000000 ;


endmodule
