# The following variables contains the files used by the different stages of the build process.
set(probe_5028_devkit_firmware_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${probe_5028_devkit_firmware_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${probe_5028_devkit_firmware_default_default_XC8_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(probe_5028_devkit_firmware_default_default_XC8_FILE_TYPE_assemblePreprocess "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/protected_io.S")
set_source_files_properties(${probe_5028_devkit_firmware_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${probe_5028_devkit_firmware_default_default_XC8_FILE_TYPE_assemblePreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(probe_5028_devkit_firmware_default_default_XC8_FILE_TYPE_compile
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/main.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/adc/src/adc0.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/dac/src/dac0.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/nvm/src/nvm.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/clock.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/config_bits.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/interrupt.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/pins.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/system/src/system.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/timer/src/tca0.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/uart/src/usart0.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../My_MCC_Config/mcc/mcc_generated_files/vref/src/vref.c")
set_source_files_properties(${probe_5028_devkit_firmware_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(probe_5028_devkit_firmware_default_default_XC8_FILE_TYPE_link)
set(probe_5028_devkit_firmware_default_image_name "default.elf")
set(probe_5028_devkit_firmware_default_image_base_name "default")

# The output directory of the final image.
set(probe_5028_devkit_firmware_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/probe-5028-devkit-firmware")

# The full path to the final image.
set(probe_5028_devkit_firmware_default_full_path_to_image ${probe_5028_devkit_firmware_default_output_dir}/${probe_5028_devkit_firmware_default_image_name})
