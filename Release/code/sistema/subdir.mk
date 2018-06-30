################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/sistema/configuration.cpp \
../code/sistema/module.cpp \
../code/sistema/propertiesProvider.cpp \
../code/sistema/property.cpp \
../code/sistema/propertyContainer.cpp 

OBJS += \
./code/sistema/configuration.o \
./code/sistema/module.o \
./code/sistema/propertiesProvider.o \
./code/sistema/property.o \
./code/sistema/propertyContainer.o 

CPP_DEPS += \
./code/sistema/configuration.d \
./code/sistema/module.d \
./code/sistema/propertiesProvider.d \
./code/sistema/property.d \
./code/sistema/propertyContainer.d 


# Each subdirectory must supply rules for building sources it contributes
code/sistema/%.o: ../code/sistema/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DOS_LINUX -DOSAPI_TRACING -I/home/joao/workspace/osapi_plus/code -I/home/joao/workspace/osapi/code -O3 -Wall -Wconversion -c -fmessage-length=0 -v -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


