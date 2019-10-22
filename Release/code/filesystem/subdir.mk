################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/filesystem/directory.cpp \
../code/filesystem/element.cpp \
../code/filesystem/file.cpp \
../code/filesystem/fileInfo.cpp 

OBJS += \
./code/filesystem/directory.o \
./code/filesystem/element.o \
./code/filesystem/file.o \
./code/filesystem/fileInfo.o 

CPP_DEPS += \
./code/filesystem/directory.d \
./code/filesystem/element.d \
./code/filesystem/file.d \
./code/filesystem/fileInfo.d 


# Each subdirectory must supply rules for building sources it contributes
code/filesystem/%.o: ../code/filesystem/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DOS_LINUX -DOSAPI_BASELINE_LIBRARY_C -I/usr/include -I"${OSAPI_PLUS_DIR}/code" -I"${OSAPI_DIR}/code" -O3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


