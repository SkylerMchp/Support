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
ifeq "$(wildcard nbproject/Makefile-local-pic32mk_gpl_curiosity_pro.mk)" "nbproject/Makefile-local-pic32mk_gpl_curiosity_pro.mk"
include nbproject/Makefile-local-pic32mk_gpl_curiosity_pro.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=pic32mk_gpl_curiosity_pro
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/pic32mk_gpl_curiosity_pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/pic32mk_gpl_curiosity_pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../src/config/pic32mk_gpl_curiosity_pro/peripheral/i2c/plib_i2c4.c ../src/config/pic32mk_gpl_curiosity_pro/peripheral/clk/plib_clk.c ../src/config/pic32mk_gpl_curiosity_pro/peripheral/gpio/plib_gpio.c ../src/config/pic32mk_gpl_curiosity_pro/peripheral/evic/plib_evic.c ../src/config/pic32mk_gpl_curiosity_pro/stdio/xc32_monitor.c ../src/config/pic32mk_gpl_curiosity_pro/initialization.c ../src/config/pic32mk_gpl_curiosity_pro/interrupts.c ../src/config/pic32mk_gpl_curiosity_pro/exceptions.c ../src/main_pic32mk_gpl_curiosity_pro.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1435921362/plib_i2c4.o ${OBJECTDIR}/_ext/1435925322/plib_clk.o ${OBJECTDIR}/_ext/1563888965/plib_gpio.o ${OBJECTDIR}/_ext/1563942793/plib_evic.o ${OBJECTDIR}/_ext/1349068802/xc32_monitor.o ${OBJECTDIR}/_ext/517903800/initialization.o ${OBJECTDIR}/_ext/517903800/interrupts.o ${OBJECTDIR}/_ext/517903800/exceptions.o ${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1435921362/plib_i2c4.o.d ${OBJECTDIR}/_ext/1435925322/plib_clk.o.d ${OBJECTDIR}/_ext/1563888965/plib_gpio.o.d ${OBJECTDIR}/_ext/1563942793/plib_evic.o.d ${OBJECTDIR}/_ext/1349068802/xc32_monitor.o.d ${OBJECTDIR}/_ext/517903800/initialization.o.d ${OBJECTDIR}/_ext/517903800/interrupts.o.d ${OBJECTDIR}/_ext/517903800/exceptions.o.d ${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1435921362/plib_i2c4.o ${OBJECTDIR}/_ext/1435925322/plib_clk.o ${OBJECTDIR}/_ext/1563888965/plib_gpio.o ${OBJECTDIR}/_ext/1563942793/plib_evic.o ${OBJECTDIR}/_ext/1349068802/xc32_monitor.o ${OBJECTDIR}/_ext/517903800/initialization.o ${OBJECTDIR}/_ext/517903800/interrupts.o ${OBJECTDIR}/_ext/517903800/exceptions.o ${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o

# Source Files
SOURCEFILES=../src/config/pic32mk_gpl_curiosity_pro/peripheral/i2c/plib_i2c4.c ../src/config/pic32mk_gpl_curiosity_pro/peripheral/clk/plib_clk.c ../src/config/pic32mk_gpl_curiosity_pro/peripheral/gpio/plib_gpio.c ../src/config/pic32mk_gpl_curiosity_pro/peripheral/evic/plib_evic.c ../src/config/pic32mk_gpl_curiosity_pro/stdio/xc32_monitor.c ../src/config/pic32mk_gpl_curiosity_pro/initialization.c ../src/config/pic32mk_gpl_curiosity_pro/interrupts.c ../src/config/pic32mk_gpl_curiosity_pro/exceptions.c ../src/main_pic32mk_gpl_curiosity_pro.c



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
	${MAKE}  -f nbproject/Makefile-pic32mk_gpl_curiosity_pro.mk dist/${CND_CONF}/${IMAGE_TYPE}/pic32mk_gpl_curiosity_pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MK1024GPL100
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
${OBJECTDIR}/_ext/1435921362/plib_i2c4.o: ../src/config/pic32mk_gpl_curiosity_pro/peripheral/i2c/plib_i2c4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1435921362" 
	@${RM} ${OBJECTDIR}/_ext/1435921362/plib_i2c4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1435921362/plib_i2c4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1435921362/plib_i2c4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1435921362/plib_i2c4.o.d" -o ${OBJECTDIR}/_ext/1435921362/plib_i2c4.o ../src/config/pic32mk_gpl_curiosity_pro/peripheral/i2c/plib_i2c4.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1435925322/plib_clk.o: ../src/config/pic32mk_gpl_curiosity_pro/peripheral/clk/plib_clk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1435925322" 
	@${RM} ${OBJECTDIR}/_ext/1435925322/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1435925322/plib_clk.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1435925322/plib_clk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1435925322/plib_clk.o.d" -o ${OBJECTDIR}/_ext/1435925322/plib_clk.o ../src/config/pic32mk_gpl_curiosity_pro/peripheral/clk/plib_clk.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1563888965/plib_gpio.o: ../src/config/pic32mk_gpl_curiosity_pro/peripheral/gpio/plib_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1563888965" 
	@${RM} ${OBJECTDIR}/_ext/1563888965/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1563888965/plib_gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1563888965/plib_gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1563888965/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/1563888965/plib_gpio.o ../src/config/pic32mk_gpl_curiosity_pro/peripheral/gpio/plib_gpio.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1563942793/plib_evic.o: ../src/config/pic32mk_gpl_curiosity_pro/peripheral/evic/plib_evic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1563942793" 
	@${RM} ${OBJECTDIR}/_ext/1563942793/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1563942793/plib_evic.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1563942793/plib_evic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1563942793/plib_evic.o.d" -o ${OBJECTDIR}/_ext/1563942793/plib_evic.o ../src/config/pic32mk_gpl_curiosity_pro/peripheral/evic/plib_evic.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1349068802/xc32_monitor.o: ../src/config/pic32mk_gpl_curiosity_pro/stdio/xc32_monitor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1349068802" 
	@${RM} ${OBJECTDIR}/_ext/1349068802/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1349068802/xc32_monitor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1349068802/xc32_monitor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1349068802/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/1349068802/xc32_monitor.o ../src/config/pic32mk_gpl_curiosity_pro/stdio/xc32_monitor.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/517903800/initialization.o: ../src/config/pic32mk_gpl_curiosity_pro/initialization.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/517903800" 
	@${RM} ${OBJECTDIR}/_ext/517903800/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/517903800/initialization.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/517903800/initialization.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/517903800/initialization.o.d" -o ${OBJECTDIR}/_ext/517903800/initialization.o ../src/config/pic32mk_gpl_curiosity_pro/initialization.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/517903800/interrupts.o: ../src/config/pic32mk_gpl_curiosity_pro/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/517903800" 
	@${RM} ${OBJECTDIR}/_ext/517903800/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/517903800/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/517903800/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/517903800/interrupts.o.d" -o ${OBJECTDIR}/_ext/517903800/interrupts.o ../src/config/pic32mk_gpl_curiosity_pro/interrupts.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/517903800/exceptions.o: ../src/config/pic32mk_gpl_curiosity_pro/exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/517903800" 
	@${RM} ${OBJECTDIR}/_ext/517903800/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/517903800/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/517903800/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/517903800/exceptions.o.d" -o ${OBJECTDIR}/_ext/517903800/exceptions.o ../src/config/pic32mk_gpl_curiosity_pro/exceptions.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o: ../src/main_pic32mk_gpl_curiosity_pro.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o.d" -o ${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o ../src/main_pic32mk_gpl_curiosity_pro.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/1435921362/plib_i2c4.o: ../src/config/pic32mk_gpl_curiosity_pro/peripheral/i2c/plib_i2c4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1435921362" 
	@${RM} ${OBJECTDIR}/_ext/1435921362/plib_i2c4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1435921362/plib_i2c4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1435921362/plib_i2c4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1435921362/plib_i2c4.o.d" -o ${OBJECTDIR}/_ext/1435921362/plib_i2c4.o ../src/config/pic32mk_gpl_curiosity_pro/peripheral/i2c/plib_i2c4.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1435925322/plib_clk.o: ../src/config/pic32mk_gpl_curiosity_pro/peripheral/clk/plib_clk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1435925322" 
	@${RM} ${OBJECTDIR}/_ext/1435925322/plib_clk.o.d 
	@${RM} ${OBJECTDIR}/_ext/1435925322/plib_clk.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1435925322/plib_clk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1435925322/plib_clk.o.d" -o ${OBJECTDIR}/_ext/1435925322/plib_clk.o ../src/config/pic32mk_gpl_curiosity_pro/peripheral/clk/plib_clk.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1563888965/plib_gpio.o: ../src/config/pic32mk_gpl_curiosity_pro/peripheral/gpio/plib_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1563888965" 
	@${RM} ${OBJECTDIR}/_ext/1563888965/plib_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1563888965/plib_gpio.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1563888965/plib_gpio.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1563888965/plib_gpio.o.d" -o ${OBJECTDIR}/_ext/1563888965/plib_gpio.o ../src/config/pic32mk_gpl_curiosity_pro/peripheral/gpio/plib_gpio.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1563942793/plib_evic.o: ../src/config/pic32mk_gpl_curiosity_pro/peripheral/evic/plib_evic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1563942793" 
	@${RM} ${OBJECTDIR}/_ext/1563942793/plib_evic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1563942793/plib_evic.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1563942793/plib_evic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1563942793/plib_evic.o.d" -o ${OBJECTDIR}/_ext/1563942793/plib_evic.o ../src/config/pic32mk_gpl_curiosity_pro/peripheral/evic/plib_evic.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1349068802/xc32_monitor.o: ../src/config/pic32mk_gpl_curiosity_pro/stdio/xc32_monitor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1349068802" 
	@${RM} ${OBJECTDIR}/_ext/1349068802/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1349068802/xc32_monitor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1349068802/xc32_monitor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1349068802/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/1349068802/xc32_monitor.o ../src/config/pic32mk_gpl_curiosity_pro/stdio/xc32_monitor.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/517903800/initialization.o: ../src/config/pic32mk_gpl_curiosity_pro/initialization.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/517903800" 
	@${RM} ${OBJECTDIR}/_ext/517903800/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/517903800/initialization.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/517903800/initialization.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/517903800/initialization.o.d" -o ${OBJECTDIR}/_ext/517903800/initialization.o ../src/config/pic32mk_gpl_curiosity_pro/initialization.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/517903800/interrupts.o: ../src/config/pic32mk_gpl_curiosity_pro/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/517903800" 
	@${RM} ${OBJECTDIR}/_ext/517903800/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/517903800/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/517903800/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/517903800/interrupts.o.d" -o ${OBJECTDIR}/_ext/517903800/interrupts.o ../src/config/pic32mk_gpl_curiosity_pro/interrupts.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/517903800/exceptions.o: ../src/config/pic32mk_gpl_curiosity_pro/exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/517903800" 
	@${RM} ${OBJECTDIR}/_ext/517903800/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/517903800/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/517903800/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/517903800/exceptions.o.d" -o ${OBJECTDIR}/_ext/517903800/exceptions.o ../src/config/pic32mk_gpl_curiosity_pro/exceptions.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o: ../src/main_pic32mk_gpl_curiosity_pro.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/config/pic32mk_gpl_curiosity_pro" -I"../src/packs/PIC32MK1024GPL100_DFP" -I"../src/mips" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o.d" -o ${OBJECTDIR}/_ext/1360937237/main_pic32mk_gpl_curiosity_pro.o ../src/main_pic32mk_gpl_curiosity_pro.c    -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/pic32mk_gpl_curiosity_pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_REAL_ICE=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/pic32mk_gpl_curiosity_pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x36F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,--defsym=_min_heap_size=512,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/pic32mk_gpl_curiosity_pro.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/pic32mk_gpl_curiosity_pro.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_pic32mk_gpl_curiosity_pro=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/pic32mk_gpl_curiosity_pro.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/pic32mk_gpl_curiosity_pro
	${RM} -r dist/pic32mk_gpl_curiosity_pro
