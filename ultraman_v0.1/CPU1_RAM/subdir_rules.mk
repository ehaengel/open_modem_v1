################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
F2837xS_CodeStartBranch.obj: /home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/source/F2837xS_CodeStartBranch.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"" -v28 -ml -mt --vcu_support=vcu2 --tmu_support=tmu0 --cla_support=cla1 --float_support=fpu32 --include_path="/opt/ti/ccsv8/ccs_base/c2000/include" --include_path="/home/ehaengel/workspace_v8/trapezium_v0.1" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/cmd" --include_path="/opt/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/headers/include" -g --define=CPU1 --display_error_number --diag_suppress=10063 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xS_CodeStartBranch.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_DefaultISR.obj: /home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/source/F2837xS_DefaultISR.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"" -v28 -ml -mt --vcu_support=vcu2 --tmu_support=tmu0 --cla_support=cla1 --float_support=fpu32 --include_path="/opt/ti/ccsv8/ccs_base/c2000/include" --include_path="/home/ehaengel/workspace_v8/trapezium_v0.1" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/cmd" --include_path="/opt/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/headers/include" -g --define=CPU1 --display_error_number --diag_suppress=10063 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xS_DefaultISR.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_GlobalVariableDefs.obj: /home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/headers/source/F2837xS_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"" -v28 -ml -mt --vcu_support=vcu2 --tmu_support=tmu0 --cla_support=cla1 --float_support=fpu32 --include_path="/opt/ti/ccsv8/ccs_base/c2000/include" --include_path="/home/ehaengel/workspace_v8/trapezium_v0.1" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/cmd" --include_path="/opt/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/headers/include" -g --define=CPU1 --display_error_number --diag_suppress=10063 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xS_GlobalVariableDefs.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_Gpio.obj: /home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/source/F2837xS_Gpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"" -v28 -ml -mt --vcu_support=vcu2 --tmu_support=tmu0 --cla_support=cla1 --float_support=fpu32 --include_path="/opt/ti/ccsv8/ccs_base/c2000/include" --include_path="/home/ehaengel/workspace_v8/trapezium_v0.1" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/cmd" --include_path="/opt/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/headers/include" -g --define=CPU1 --display_error_number --diag_suppress=10063 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xS_Gpio.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_PieCtrl.obj: /home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/source/F2837xS_PieCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"" -v28 -ml -mt --vcu_support=vcu2 --tmu_support=tmu0 --cla_support=cla1 --float_support=fpu32 --include_path="/opt/ti/ccsv8/ccs_base/c2000/include" --include_path="/home/ehaengel/workspace_v8/trapezium_v0.1" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/cmd" --include_path="/opt/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/headers/include" -g --define=CPU1 --display_error_number --diag_suppress=10063 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xS_PieCtrl.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_PieVect.obj: /home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/source/F2837xS_PieVect.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"" -v28 -ml -mt --vcu_support=vcu2 --tmu_support=tmu0 --cla_support=cla1 --float_support=fpu32 --include_path="/opt/ti/ccsv8/ccs_base/c2000/include" --include_path="/home/ehaengel/workspace_v8/trapezium_v0.1" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/cmd" --include_path="/opt/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/headers/include" -g --define=CPU1 --display_error_number --diag_suppress=10063 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xS_PieVect.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_SysCtrl.obj: /home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/source/F2837xS_SysCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"" -v28 -ml -mt --vcu_support=vcu2 --tmu_support=tmu0 --cla_support=cla1 --float_support=fpu32 --include_path="/opt/ti/ccsv8/ccs_base/c2000/include" --include_path="/home/ehaengel/workspace_v8/trapezium_v0.1" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/cmd" --include_path="/opt/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/headers/include" -g --define=CPU1 --display_error_number --diag_suppress=10063 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xS_SysCtrl.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

F2837xS_usDelay.obj: /home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/source/F2837xS_usDelay.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"" -v28 -ml -mt --vcu_support=vcu2 --tmu_support=tmu0 --cla_support=cla1 --float_support=fpu32 --include_path="/opt/ti/ccsv8/ccs_base/c2000/include" --include_path="/home/ehaengel/workspace_v8/trapezium_v0.1" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/cmd" --include_path="/opt/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/headers/include" -g --define=CPU1 --display_error_number --diag_suppress=10063 --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xS_usDelay.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

bmi160.obj: ../bmi160.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"" -v28 -ml -mt --vcu_support=vcu2 --tmu_support=tmu0 --cla_support=cla1 --float_support=fpu32 --include_path="/opt/ti/ccsv8/ccs_base/c2000/include" --include_path="/home/ehaengel/workspace_v8/trapezium_v0.1" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/cmd" --include_path="/opt/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/headers/include" -g --define=CPU1 --display_error_number --diag_suppress=10063 --diag_warning=225 --preproc_with_compile --preproc_dependency="bmi160.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

blinky_cpu01.obj: /home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/examples/cpu1/blinky/cpu01/blinky_cpu01.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"" -v28 -ml -mt --vcu_support=vcu2 --tmu_support=tmu0 --cla_support=cla1 --float_support=fpu32 --include_path="/opt/ti/ccsv8/ccs_base/c2000/include" --include_path="/home/ehaengel/workspace_v8/trapezium_v0.1" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/cmd" --include_path="/opt/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/headers/include" -g --define=CPU1 --display_error_number --diag_suppress=10063 --diag_warning=225 --preproc_with_compile --preproc_dependency="main.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

serial_communications.obj: ../serial_communications.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"" -v28 -ml -mt --vcu_support=vcu2 --tmu_support=tmu0 --cla_support=cla1 --float_support=fpu32 --include_path="/opt/ti/ccsv8/ccs_base/c2000/include" --include_path="/home/ehaengel/workspace_v8/trapezium_v0.1" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/cmd" --include_path="/opt/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/headers/include" -g --define=CPU1 --display_error_number --diag_suppress=10063 --diag_warning=225 --preproc_with_compile --preproc_dependency="serial_communications.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '

tlc59731_firmware.obj: ../tlc59731_firmware.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"" -v28 -ml -mt --vcu_support=vcu2 --tmu_support=tmu0 --cla_support=cla1 --float_support=fpu32 --include_path="/opt/ti/ccsv8/ccs_base/c2000/include" --include_path="/home/ehaengel/workspace_v8/trapezium_v0.1" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/cmd" --include_path="/opt/ti/ccsv8/tools/compiler/ti-cgt-c2000_18.1.2.LTS/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/common/include" --include_path="/home/ehaengel/ti/C2000Ware_1_00_05_00_Software/device_support/f2837xs/headers/include" -g --define=CPU1 --display_error_number --diag_suppress=10063 --diag_warning=225 --preproc_with_compile --preproc_dependency="tlc59731_firmware.d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


