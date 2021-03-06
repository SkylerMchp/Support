#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-pic32mz_EFM.mk)" "nbproject/Makefile-local-pic32mz_EFM.mk"
include nbproject/Makefile-local-pic32mz_EFM.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=pic32mz_EFM
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/i2cEFMDemo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/i2cEFMDemo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/config/pic32mz_w1_curiosity/peripheral/clk/plib_clk.c ../src/config/pic32mz_w1_curiosity/peripheral/evic/plib_evic.c ../src/config/pic32mz_w1_curiosity/peripheral/gpio/plib_gpio.c ../src/config/pic32mz_w1_curiosity/peripheral/i2c/plib_i2c1.c ../src/config/pic32mz_w1_curiosity/stdio/xc32_monitor.c ../src/config/pic32mz_w1_curiosity/initialization.c ../src/config/pic32mz_w1_curiosity/interrupts.c ../src/config/pic32mz_w1_curiosity/exceptions.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1481979610/plib_clk.o ${OBJECTDIR}/_ext/1303341575/plib_evic.o ${OBJECTDIR}/_ext/1303395403/plib_gpio.o ${OBJECTDIR}/_ext/1481975650/plib_i2c1.o ${OBJECTDIR}/_ext/1903942254/xc32_monitor.o ${OBJECTDIR}/_ext/1737632808/initialization.o ${OBJECTDIR}/_ext/1737632808/interrupts.o ${OBJECTDIR}/_ext/1737632808/exceptions.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1481979610/plib_clk.o.d ${OBJECTDIR}/_ext/1303341575/plib_evic.o.d ${OBJECTDIR}/_ext/1303395403/plib_gpio.o.d ${OBJECTDIR}/_ext/1481975650/plib_i2c1.o.d ${OBJECTDIR}/_ext/1903942254/xc32_monitor.o.d ${OBJECTDIR}/_ext/1737632808/initialization.o.d ${OBJECTDIR}/_ext/1737632808/interrupts.o.d ${OBJECTDIR}/_ext/1737632808/exceptions.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1481979610/plib_clk.o ${OBJECTDIR}/_ext/1303341575/plib_evic.o ${OBJECTDIR}/_ext/1303395403/plib_gpio.o ${OBJECTDIR}/_ext/1481975650/plib_i2c1.o ${OBJECTDIR}/_ext/1903942254/xc32_monitor.o ${OBJECTDIR}/_ext/1737632808/initialization.o ${OBJECTDIR}/_ext/1737632808/interrupts.o ${OBJECTDIR}/_ext/1737632808/exceptions.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../src/config/pic32mz_w1_curiosity/peripheral/clk/plib_clk.c ../src/config/pic32mz_w1_curiosity/peripheral/evic/plib_evic.c ../src/config/pic32mz_w1_curiosity/peripheral/gpio/plib_gpio.c ../src/config/pic32mz_w1_curiosity/peripheral/i2c/plib_i2c1.c ../src/config/pic32mz_w1_curiosity/stdio/xc32_monitor.c ../src/config/pic32mz_w1_curiosity/initialization.c ../src/config/pic32mz_w1_curiosity/interrupts.c ../src/config/pic32mz_w1_curiosity/exceptions.c ../src/main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-pic32mz_EFM.mk dist/${CND_CONF}/${IMAGE_TYPE}/i2cEFMDemo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ2048EFM144
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1481979610/plib_clk.o: ../src/config/pic32mz_w1_curiosity/peripheral/clk/plib_clk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1481979610" 
	@${RM} ${OBJECTDIR}/_ext/1481979610/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1481979610/plib_clk.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1481979610/plib_clk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1481979610/plib_clk.o.d" -o ${OBJECTDIR}/_ext/1481979610/plib_clk.o ../src/config/pic32mz_w1_curiosity/peripheral/clk/plib_clk.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1303341575/plib_evic.o: ../src/config/pic32mz_w1_curiosity/peripheral/evic/plib_evic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1303341575" 
	@${RM} ${OBJECTDIR}/_ext/1303341575/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1303341575/plib_evic.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1303341575/plib_evic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1303341575/plib_evic.o.d" -o ${OBJECTDIR}/_ext/1303341575/plib_evic.o ../src/config/pic32mz_w1_curiosity/peripheral/evic/plib_evic.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1303395403/plib_gpio.o: ../src/config/pic32mz_w1_curiosity/peripheral/gpio/plib_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1303395403" 
	@${RM} ${OBJECTDIR}/_ext/1303395403/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1303395403/plib_gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1303395403/plib_gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1303395403/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/1303395403/plib_gpio.o ../src/config/pic32mz_w1_curiosity/peripheral/gpio/plib_gpio.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1481975650/plib_i2c1.o: ../src/config/pic32mz_w1_curiosity/peripheral/i2c/plib_i2c1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1481975650" 
	@${RM} ${OBJECTDIR}/_ext/1481975650/plib_i2c1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1481975650/plib_i2c1.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1481975650/plib_i2c1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1481975650/plib_i2c1.o.d" -o ${OBJECTDIR}/_ext/1481975650/plib_i2c1.o ../src/config/pic32mz_w1_curiosity/peripheral/i2c/plib_i2c1.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1903942254/xc32_monitor.o: ../src/config/pic32mz_w1_curiosity/stdio/xc32_monitor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1903942254" 
	@${RM} ${OBJECTDIR}/_ext/1903942254/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1903942254/xc32_monitor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1903942254/xc32_monitor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1903942254/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/1903942254/xc32_monitor.o ../src/config/pic32mz_w1_curiosity/stdio/xc32_monitor.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1737632808/initialization.o: ../src/config/pic32mz_w1_curiosity/initialization.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1737632808" 
	@${RM} ${OBJECTDIR}/_ext/1737632808/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1737632808/initialization.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1737632808/initialization.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1737632808/initialization.o.d" -o ${OBJECTDIR}/_ext/1737632808/initialization.o ../src/config/pic32mz_w1_curiosity/initialization.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1737632808/interrupts.o: ../src/config/pic32mz_w1_curiosity/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1737632808" 
	@${RM} ${OBJECTDIR}/_ext/1737632808/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1737632808/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1737632808/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1737632808/interrupts.o.d" -o ${OBJECTDIR}/_ext/1737632808/interrupts.o ../src/config/pic32mz_w1_curiosity/interrupts.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1737632808/exceptions.o: ../src/config/pic32mz_w1_curiosity/exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1737632808" 
	@${RM} ${OBJECTDIR}/_ext/1737632808/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1737632808/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1737632808/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1737632808/exceptions.o.d" -o ${OBJECTDIR}/_ext/1737632808/exceptions.o ../src/config/pic32mz_w1_curiosity/exceptions.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
else
${OBJECTDIR}/_ext/1481979610/plib_clk.o: ../src/config/pic32mz_w1_curiosity/peripheral/clk/plib_clk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1481979610" 
	@${RM} ${OBJECTDIR}/_ext/1481979610/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1481979610/plib_clk.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1481979610/plib_clk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1481979610/plib_clk.o.d" -o ${OBJECTDIR}/_ext/1481979610/plib_clk.o ../src/config/pic32mz_w1_curiosity/peripheral/clk/plib_clk.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1303341575/plib_evic.o: ../src/config/pic32mz_w1_curiosity/peripheral/evic/plib_evic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1303341575" 
	@${RM} ${OBJECTDIR}/_ext/1303341575/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1303341575/plib_evic.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1303341575/plib_evic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1303341575/plib_evic.o.d" -o ${OBJECTDIR}/_ext/1303341575/plib_evic.o ../src/config/pic32mz_w1_curiosity/peripheral/evic/plib_evic.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1303395403/plib_gpio.o: ../src/config/pic32mz_w1_curiosity/peripheral/gpio/plib_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1303395403" 
	@${RM} ${OBJECTDIR}/_ext/1303395403/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1303395403/plib_gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1303395403/plib_gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1303395403/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/1303395403/plib_gpio.o ../src/config/pic32mz_w1_curiosity/peripheral/gpio/plib_gpio.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1481975650/plib_i2c1.o: ../src/config/pic32mz_w1_curiosity/peripheral/i2c/plib_i2c1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1481975650" 
	@${RM} ${OBJECTDIR}/_ext/1481975650/plib_i2c1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1481975650/plib_i2c1.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1481975650/plib_i2c1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1481975650/plib_i2c1.o.d" -o ${OBJECTDIR}/_ext/1481975650/plib_i2c1.o ../src/config/pic32mz_w1_curiosity/peripheral/i2c/plib_i2c1.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1903942254/xc32_monitor.o: ../src/config/pic32mz_w1_curiosity/stdio/xc32_monitor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1903942254" 
	@${RM} ${OBJECTDIR}/_ext/1903942254/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1903942254/xc32_monitor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1903942254/xc32_monitor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1903942254/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/1903942254/xc32_monitor.o ../src/config/pic32mz_w1_curiosity/stdio/xc32_monitor.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1737632808/initialization.o: ../src/config/pic32mz_w1_curiosity/initialization.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1737632808" 
	@${RM} ${OBJECTDIR}/_ext/1737632808/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1737632808/initialization.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1737632808/initialization.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1737632808/initialization.o.d" -o ${OBJECTDIR}/_ext/1737632808/initialization.o ../src/config/pic32mz_w1_curiosity/initialization.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1737632808/interrupts.o: ../src/config/pic32mz_w1_curiosity/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1737632808" 
	@${RM} ${OBJECTDIR}/_ext/1737632808/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1737632808/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1737632808/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1737632808/interrupts.o.d" -o ${OBJECTDIR}/_ext/1737632808/interrupts.o ../src/config/pic32mz_w1_curiosity/interrupts.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1737632808/exceptions.o: ../src/config/pic32mz_w1_curiosity/exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1737632808" 
	@${RM} ${OBJECTDIR}/_ext/1737632808/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1737632808/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1737632808/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1737632808/exceptions.o.d" -o ${OBJECTDIR}/_ext/1737632808/exceptions.o ../src/config/pic32mz_w1_curiosity/exceptions.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mz_w1_curiosity" -I"../src/packs/PIC32MZ2048EFM144_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -mdfp=${DFP_DIR}  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/i2cEFMDemo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/i2cEFMDemo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=512,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp=${DFP_DIR}
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/i2cEFMDemo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/i2cEFMDemo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_pic32mz_EFM=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp=${DFP_DIR}
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/i2cEFMDemo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/pic32mz_EFM
	${RM} -r dist/pic32mz_EFM

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
