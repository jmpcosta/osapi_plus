################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/configuration/argItem.cpp \
../code/configuration/ciContainer.cpp \
../code/configuration/configuration.cpp \
../code/configuration/configurationFileParser.cpp \
../code/configuration/configurationItem.cpp \
../code/configuration/configurationParser.cpp \
../code/configuration/configurationProvider.cpp \
../code/configuration/propertyItem.cpp 

OBJS += \
./code/configuration/argItem.o \
./code/configuration/ciContainer.o \
./code/configuration/configuration.o \
./code/configuration/configurationFileParser.o \
./code/configuration/configurationItem.o \
./code/configuration/configurationParser.o \
./code/configuration/configurationProvider.o \
./code/configuration/propertyItem.o 

CPP_DEPS += \
./code/configuration/argItem.d \
./code/configuration/ciContainer.d \
./code/configuration/configuration.d \
./code/configuration/configurationFileParser.d \
./code/configuration/configurationItem.d \
./code/configuration/configurationParser.d \
./code/configuration/configurationProvider.d \
./code/configuration/propertyItem.d 


# Each subdirectory must supply rules for building sources it contributes
code/configuration/%.o: ../code/configuration/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DOS_LINUX -I../code -I../../osapi/code -I/usr/include -I"/osapi/code" -I"/osapi_plus/code" -O3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


