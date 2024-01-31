set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

set(CMAKE_C_COMPILER "aarch64-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER "aarch64-linux-gnu-g++")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_SYSROOT "/opt/petalinux/2021.2/sysroots/cortexa72-cortexa53-xilinx-linux")
set(CMAKE_C_FLAGS "-mcpu=cortex-a72.cortex-a53 -march=armv8-a+crc -fstack-protector-strong  -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security -fno-rtti -fno-exceptions -flto -ffunction-sections -fdata-sections -fno-unwind-tables -fno-asynchronous-unwind-tables -feliminate-unused-debug-types --sysroot=/opt/petalinux/2021.2/sysroots/cortexa72-cortexa53-xilinx-linux")
set(CMAKE_CXX_FLAGS "-mcpu=cortex-a72.cortex-a53 -march=armv8-a+crc -fstack-protector-strong  -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security -fno-rtti -fno-exceptions -flto -ffunction-sections -fdata-sections -fno-unwind-tables -fno-asynchronous-unwind-tables -feliminate-unused-debug-types --sysroot=/opt/petalinux/2021.2/sysroots/cortexa72-cortexa53-xilinx-linux")

# cache flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}" CACHE STRING "c flags")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" CACHE STRING "c++ flags")
