# 
# Synthesis run script generated by Vivado
# 

set_param xicom.use_bs_reader 1
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7a35ticpg236-1L

set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir C:/Users/darthpbal/Documents/GitHub/helperToolsAndFiles/languages/verilog/60SecTimer/vivado_src/vivado_src.cache/wt [current_project]
set_property parent.project_path C:/Users/darthpbal/Documents/GitHub/helperToolsAndFiles/languages/verilog/60SecTimer/vivado_src/vivado_src.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property vhdl_version vhdl_2k [current_fileset]
read_verilog -library xil_defaultlib {
  C:/Users/darthpbal/Documents/GitHub/helperToolsAndFiles/languages/verilog/60SecTimer/src/debounce.v
  C:/Users/darthpbal/Documents/GitHub/helperToolsAndFiles/languages/verilog/60SecTimer/src/SevSegDriver.v
  C:/Users/darthpbal/Documents/GitHub/helperToolsAndFiles/languages/verilog/60SecTimer/src/timer.v
}
read_xdc C:/Users/darthpbal/Documents/GitHub/helperToolsAndFiles/languages/verilog/60SecTimer/src/basys.xdc
set_property used_in_implementation false [get_files C:/Users/darthpbal/Documents/GitHub/helperToolsAndFiles/languages/verilog/60SecTimer/src/basys.xdc]

synth_design -top timer -part xc7a35ticpg236-1L
write_checkpoint -noxdef timer.dcp
catch { report_utilization -file timer_utilization_synth.rpt -pb timer_utilization_synth.pb }