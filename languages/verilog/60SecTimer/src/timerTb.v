`timescale 1ns / 1ps
module timer_tb ();
    reg clk, btnC;
    wire [3:0] segEn;
    wire [6:0] seg;

    timer dut(
            .clk(clk),
            .btnC(btnC),
            .segEn(segEn),
            .seg(seg)
        );

    parameter clk_period = 100000000;
    always #clk_period clk = ~clk;

    initial begin
        clk = 0;
        btnC = 1;
        #100 btnC = 0;
        #(clk_period * 4) btnC = 1;
        #(clk_period * 4) $finish;
    end
endmodule
