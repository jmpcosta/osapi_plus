################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/configuration/Provider.cpp \
../code/configuration/argItem.cpp \
../code/configuration/configuration.cpp \
../code/configuration/container.cpp \
../code/configuration/fileParser.cpp \
../code/configuration/item.cpp \
../code/configuration/parser.cpp \
../code/configuration/propertyItem.cpp 

OBJS += \
./code/configuration/Provider.o \
./code/configuration/argItem.o \
./code/configuration/configuration.o \
./code/configuration/container.o \
./code/configuration/fileParser.o \
./code/configuration/item.o \
./code/configuration/parser.o \
./code/configuration/propertyItem.o 

CPP_DEPS += \
./code/configuration/Provider.d \
./code/configuration/argItem.d \
./code/configuration/configuration.d \
./code/configuration/container.d \
./code/configuration/fileParser.d \
./code/configuration/item.d \
./code/configuration/parser.d \
./code/configuration/propertyItem.d 


# Each subdirectory must supply rules for building sources it contributes
code/configuration/%.o: ../code/configuration/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DOS_LINUX -DOSAPI_BASELINE_LIBRARY_C -I/usr/include -I"${OSAPI_PLUS_DIR}/code" -I"${OSAPI_DIR}/code" -O3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


