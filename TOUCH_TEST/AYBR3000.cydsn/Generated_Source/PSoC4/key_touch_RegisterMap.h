/***************************************************************************//**
* \file key_touch_RegisterMap.h
* \version 3.10
*
* \brief
*   This file provides the definitions for the component data structure register.
*
* \see CapSense P4 v3.10 Datasheet
*
*//*****************************************************************************
* Copyright (2016), Cypress Semiconductor Corporation.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*******************************************************************************/

#if !defined(CY_CAPSENSE_key_touch_REGISTER_MAP_H)
#define CY_CAPSENSE_key_touch_REGISTER_MAP_H

#include <cytypes.h>
#include "key_touch_Configuration.h"
#include "key_touch_Structure.h"

/*****************************************************************************/
/* RAM Data structure register definitions                                   */
/*****************************************************************************/
#define key_touch_CONFIG_ID_VALUE                           (key_touch_dsRam.configId)
#define key_touch_CONFIG_ID_OFFSET                          (0u)
#define key_touch_CONFIG_ID_SIZE                            (2u)
#define key_touch_CONFIG_ID_PARAM_ID                        (0x87000000u)

#define key_touch_DEVICE_ID_VALUE                           (key_touch_dsRam.deviceId)
#define key_touch_DEVICE_ID_OFFSET                          (2u)
#define key_touch_DEVICE_ID_SIZE                            (2u)
#define key_touch_DEVICE_ID_PARAM_ID                        (0x8B000002u)

#define key_touch_TUNER_CMD_VALUE                           (key_touch_dsRam.tunerCmd)
#define key_touch_TUNER_CMD_OFFSET                          (4u)
#define key_touch_TUNER_CMD_SIZE                            (2u)
#define key_touch_TUNER_CMD_PARAM_ID                        (0xAD000004u)

#define key_touch_SCAN_COUNTER_VALUE                        (key_touch_dsRam.scanCounter)
#define key_touch_SCAN_COUNTER_OFFSET                       (6u)
#define key_touch_SCAN_COUNTER_SIZE                         (2u)
#define key_touch_SCAN_COUNTER_PARAM_ID                     (0x8A000006u)

#define key_touch_STATUS_VALUE                              (key_touch_dsRam.status)
#define key_touch_STATUS_OFFSET                             (8u)
#define key_touch_STATUS_SIZE                               (4u)
#define key_touch_STATUS_PARAM_ID                           (0xCA000008u)

#define key_touch_WDGT_ENABLE0_VALUE                        (key_touch_dsRam.wdgtEnable[0u])
#define key_touch_WDGT_ENABLE0_OFFSET                       (12u)
#define key_touch_WDGT_ENABLE0_SIZE                         (4u)
#define key_touch_WDGT_ENABLE0_PARAM_ID                     (0xE000000Cu)

#define key_touch_WDGT_STATUS0_VALUE                        (key_touch_dsRam.wdgtStatus[0u])
#define key_touch_WDGT_STATUS0_OFFSET                       (16u)
#define key_touch_WDGT_STATUS0_SIZE                         (4u)
#define key_touch_WDGT_STATUS0_PARAM_ID                     (0xCD000010u)

#define key_touch_SNS_STATUS0_VALUE                         (key_touch_dsRam.snsStatus[0u])
#define key_touch_SNS_STATUS0_OFFSET                        (20u)
#define key_touch_SNS_STATUS0_SIZE                          (1u)
#define key_touch_SNS_STATUS0_PARAM_ID                      (0x4B000014u)

#define key_touch_SNS_STATUS1_VALUE                         (key_touch_dsRam.snsStatus[1u])
#define key_touch_SNS_STATUS1_OFFSET                        (21u)
#define key_touch_SNS_STATUS1_SIZE                          (1u)
#define key_touch_SNS_STATUS1_PARAM_ID                      (0x4D000015u)

#define key_touch_SNS_STATUS2_VALUE                         (key_touch_dsRam.snsStatus[2u])
#define key_touch_SNS_STATUS2_OFFSET                        (22u)
#define key_touch_SNS_STATUS2_SIZE                          (1u)
#define key_touch_SNS_STATUS2_PARAM_ID                      (0x47000016u)

#define key_touch_SNS_STATUS3_VALUE                         (key_touch_dsRam.snsStatus[3u])
#define key_touch_SNS_STATUS3_OFFSET                        (23u)
#define key_touch_SNS_STATUS3_SIZE                          (1u)
#define key_touch_SNS_STATUS3_PARAM_ID                      (0x41000017u)

#define key_touch_SNS_STATUS4_VALUE                         (key_touch_dsRam.snsStatus[4u])
#define key_touch_SNS_STATUS4_OFFSET                        (24u)
#define key_touch_SNS_STATUS4_SIZE                          (1u)
#define key_touch_SNS_STATUS4_PARAM_ID                      (0x48000018u)

#define key_touch_SNS_STATUS5_VALUE                         (key_touch_dsRam.snsStatus[5u])
#define key_touch_SNS_STATUS5_OFFSET                        (25u)
#define key_touch_SNS_STATUS5_SIZE                          (1u)
#define key_touch_SNS_STATUS5_PARAM_ID                      (0x4E000019u)

#define key_touch_SNS_STATUS6_VALUE                         (key_touch_dsRam.snsStatus[6u])
#define key_touch_SNS_STATUS6_OFFSET                        (26u)
#define key_touch_SNS_STATUS6_SIZE                          (1u)
#define key_touch_SNS_STATUS6_PARAM_ID                      (0x4400001Au)

#define key_touch_SNS_STATUS7_VALUE                         (key_touch_dsRam.snsStatus[7u])
#define key_touch_SNS_STATUS7_OFFSET                        (27u)
#define key_touch_SNS_STATUS7_SIZE                          (1u)
#define key_touch_SNS_STATUS7_PARAM_ID                      (0x4200001Bu)

#define key_touch_SNS_STATUS8_VALUE                         (key_touch_dsRam.snsStatus[8u])
#define key_touch_SNS_STATUS8_OFFSET                        (28u)
#define key_touch_SNS_STATUS8_SIZE                          (1u)
#define key_touch_SNS_STATUS8_PARAM_ID                      (0x4900001Cu)

#define key_touch_SNS_STATUS9_VALUE                         (key_touch_dsRam.snsStatus[9u])
#define key_touch_SNS_STATUS9_OFFSET                        (29u)
#define key_touch_SNS_STATUS9_SIZE                          (1u)
#define key_touch_SNS_STATUS9_PARAM_ID                      (0x4F00001Du)

#define key_touch_SNS_STATUS10_VALUE                        (key_touch_dsRam.snsStatus[10u])
#define key_touch_SNS_STATUS10_OFFSET                       (30u)
#define key_touch_SNS_STATUS10_SIZE                         (1u)
#define key_touch_SNS_STATUS10_PARAM_ID                     (0x4500001Eu)

#define key_touch_SNS_STATUS11_VALUE                        (key_touch_dsRam.snsStatus[11u])
#define key_touch_SNS_STATUS11_OFFSET                       (31u)
#define key_touch_SNS_STATUS11_SIZE                         (1u)
#define key_touch_SNS_STATUS11_PARAM_ID                     (0x4300001Fu)

#define key_touch_CSD0_CONFIG_VALUE                         (key_touch_dsRam.csd0Config)
#define key_touch_CSD0_CONFIG_OFFSET                        (32u)
#define key_touch_CSD0_CONFIG_SIZE                          (2u)
#define key_touch_CSD0_CONFIG_PARAM_ID                      (0xAB800020u)

#define key_touch_MOD_CSD_CLK_VALUE                         (key_touch_dsRam.modCsdClk)
#define key_touch_MOD_CSD_CLK_OFFSET                        (34u)
#define key_touch_MOD_CSD_CLK_SIZE                          (1u)
#define key_touch_MOD_CSD_CLK_PARAM_ID                      (0x6F800022u)

#define key_touch_SNS_CSD_CLK_VALUE                         (key_touch_dsRam.snsCsdClk)
#define key_touch_SNS_CSD_CLK_OFFSET                        (35u)
#define key_touch_SNS_CSD_CLK_SIZE                          (1u)
#define key_touch_SNS_CSD_CLK_PARAM_ID                      (0x69800023u)

#define key_touch_BUTTON0_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button0.resolution)
#define key_touch_BUTTON0_RESOLUTION_OFFSET                 (36u)
#define key_touch_BUTTON0_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON0_RESOLUTION_PARAM_ID               (0xAA800024u)

#define key_touch_BUTTON0_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button0.fingerTh)
#define key_touch_BUTTON0_FINGER_TH_OFFSET                  (38u)
#define key_touch_BUTTON0_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON0_FINGER_TH_PARAM_ID                (0xA6800026u)

#define key_touch_BUTTON0_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button0.noiseTh)
#define key_touch_BUTTON0_NOISE_TH_OFFSET                   (40u)
#define key_touch_BUTTON0_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON0_NOISE_TH_PARAM_ID                 (0x61800028u)

#define key_touch_BUTTON0_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button0.nNoiseTh)
#define key_touch_BUTTON0_NNOISE_TH_OFFSET                  (41u)
#define key_touch_BUTTON0_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON0_NNOISE_TH_PARAM_ID                (0x67800029u)

#define key_touch_BUTTON0_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button0.hysteresis)
#define key_touch_BUTTON0_HYSTERESIS_OFFSET                 (42u)
#define key_touch_BUTTON0_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON0_HYSTERESIS_PARAM_ID               (0x6D80002Au)

#define key_touch_BUTTON0_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button0.onDebounce)
#define key_touch_BUTTON0_ON_DEBOUNCE_OFFSET                (43u)
#define key_touch_BUTTON0_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON0_ON_DEBOUNCE_PARAM_ID              (0x6B80002Bu)

#define key_touch_BUTTON0_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button0.lowBslnRst)
#define key_touch_BUTTON0_LOW_BSLN_RST_OFFSET               (44u)
#define key_touch_BUTTON0_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON0_LOW_BSLN_RST_PARAM_ID             (0x6080002Cu)

#define key_touch_BUTTON0_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button0.bslnCoeff)
#define key_touch_BUTTON0_BSLN_COEFF_OFFSET                 (45u)
#define key_touch_BUTTON0_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON0_BSLN_COEFF_PARAM_ID               (0x6680002Du)

#define key_touch_BUTTON0_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button0.idacMod[0u])
#define key_touch_BUTTON0_IDAC_MOD0_OFFSET                  (46u)
#define key_touch_BUTTON0_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON0_IDAC_MOD0_PARAM_ID                (0x4A00002Eu)

#define key_touch_BUTTON0_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button0.snsClkSource)
#define key_touch_BUTTON0_SNS_CLK_SOURCE_OFFSET             (47u)
#define key_touch_BUTTON0_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON0_SNS_CLK_SOURCE_PARAM_ID           (0x4180002Fu)

#define key_touch_BUTTON1_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button1.resolution)
#define key_touch_BUTTON1_RESOLUTION_OFFSET                 (48u)
#define key_touch_BUTTON1_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON1_RESOLUTION_PARAM_ID               (0xAD810030u)

#define key_touch_BUTTON1_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button1.fingerTh)
#define key_touch_BUTTON1_FINGER_TH_OFFSET                  (50u)
#define key_touch_BUTTON1_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON1_FINGER_TH_PARAM_ID                (0xA1810032u)

#define key_touch_BUTTON1_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button1.noiseTh)
#define key_touch_BUTTON1_NOISE_TH_OFFSET                   (52u)
#define key_touch_BUTTON1_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON1_NOISE_TH_PARAM_ID                 (0x64810034u)

#define key_touch_BUTTON1_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button1.nNoiseTh)
#define key_touch_BUTTON1_NNOISE_TH_OFFSET                  (53u)
#define key_touch_BUTTON1_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON1_NNOISE_TH_PARAM_ID                (0x62810035u)

#define key_touch_BUTTON1_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button1.hysteresis)
#define key_touch_BUTTON1_HYSTERESIS_OFFSET                 (54u)
#define key_touch_BUTTON1_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON1_HYSTERESIS_PARAM_ID               (0x68810036u)

#define key_touch_BUTTON1_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button1.onDebounce)
#define key_touch_BUTTON1_ON_DEBOUNCE_OFFSET                (55u)
#define key_touch_BUTTON1_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON1_ON_DEBOUNCE_PARAM_ID              (0x6E810037u)

#define key_touch_BUTTON1_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button1.lowBslnRst)
#define key_touch_BUTTON1_LOW_BSLN_RST_OFFSET               (56u)
#define key_touch_BUTTON1_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON1_LOW_BSLN_RST_PARAM_ID             (0x67810038u)

#define key_touch_BUTTON1_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button1.bslnCoeff)
#define key_touch_BUTTON1_BSLN_COEFF_OFFSET                 (57u)
#define key_touch_BUTTON1_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON1_BSLN_COEFF_PARAM_ID               (0x61810039u)

#define key_touch_BUTTON1_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button1.idacMod[0u])
#define key_touch_BUTTON1_IDAC_MOD0_OFFSET                  (58u)
#define key_touch_BUTTON1_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON1_IDAC_MOD0_PARAM_ID                (0x4D01003Au)

#define key_touch_BUTTON1_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button1.snsClkSource)
#define key_touch_BUTTON1_SNS_CLK_SOURCE_OFFSET             (59u)
#define key_touch_BUTTON1_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON1_SNS_CLK_SOURCE_PARAM_ID           (0x4681003Bu)

#define key_touch_BUTTON2_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button2.resolution)
#define key_touch_BUTTON2_RESOLUTION_OFFSET                 (60u)
#define key_touch_BUTTON2_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON2_RESOLUTION_PARAM_ID               (0xAB82003Cu)

#define key_touch_BUTTON2_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button2.fingerTh)
#define key_touch_BUTTON2_FINGER_TH_OFFSET                  (62u)
#define key_touch_BUTTON2_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON2_FINGER_TH_PARAM_ID                (0xA782003Eu)

#define key_touch_BUTTON2_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button2.noiseTh)
#define key_touch_BUTTON2_NOISE_TH_OFFSET                   (64u)
#define key_touch_BUTTON2_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON2_NOISE_TH_PARAM_ID                 (0x62820040u)

#define key_touch_BUTTON2_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button2.nNoiseTh)
#define key_touch_BUTTON2_NNOISE_TH_OFFSET                  (65u)
#define key_touch_BUTTON2_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON2_NNOISE_TH_PARAM_ID                (0x64820041u)

#define key_touch_BUTTON2_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button2.hysteresis)
#define key_touch_BUTTON2_HYSTERESIS_OFFSET                 (66u)
#define key_touch_BUTTON2_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON2_HYSTERESIS_PARAM_ID               (0x6E820042u)

#define key_touch_BUTTON2_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button2.onDebounce)
#define key_touch_BUTTON2_ON_DEBOUNCE_OFFSET                (67u)
#define key_touch_BUTTON2_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON2_ON_DEBOUNCE_PARAM_ID              (0x68820043u)

#define key_touch_BUTTON2_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button2.lowBslnRst)
#define key_touch_BUTTON2_LOW_BSLN_RST_OFFSET               (68u)
#define key_touch_BUTTON2_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON2_LOW_BSLN_RST_PARAM_ID             (0x63820044u)

#define key_touch_BUTTON2_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button2.bslnCoeff)
#define key_touch_BUTTON2_BSLN_COEFF_OFFSET                 (69u)
#define key_touch_BUTTON2_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON2_BSLN_COEFF_PARAM_ID               (0x65820045u)

#define key_touch_BUTTON2_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button2.idacMod[0u])
#define key_touch_BUTTON2_IDAC_MOD0_OFFSET                  (70u)
#define key_touch_BUTTON2_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON2_IDAC_MOD0_PARAM_ID                (0x49020046u)

#define key_touch_BUTTON2_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button2.snsClkSource)
#define key_touch_BUTTON2_SNS_CLK_SOURCE_OFFSET             (71u)
#define key_touch_BUTTON2_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON2_SNS_CLK_SOURCE_PARAM_ID           (0x42820047u)

#define key_touch_BUTTON3_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button3.resolution)
#define key_touch_BUTTON3_RESOLUTION_OFFSET                 (72u)
#define key_touch_BUTTON3_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON3_RESOLUTION_PARAM_ID               (0xAB830048u)

#define key_touch_BUTTON3_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button3.fingerTh)
#define key_touch_BUTTON3_FINGER_TH_OFFSET                  (74u)
#define key_touch_BUTTON3_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON3_FINGER_TH_PARAM_ID                (0xA783004Au)

#define key_touch_BUTTON3_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button3.noiseTh)
#define key_touch_BUTTON3_NOISE_TH_OFFSET                   (76u)
#define key_touch_BUTTON3_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON3_NOISE_TH_PARAM_ID                 (0x6283004Cu)

#define key_touch_BUTTON3_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button3.nNoiseTh)
#define key_touch_BUTTON3_NNOISE_TH_OFFSET                  (77u)
#define key_touch_BUTTON3_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON3_NNOISE_TH_PARAM_ID                (0x6483004Du)

#define key_touch_BUTTON3_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button3.hysteresis)
#define key_touch_BUTTON3_HYSTERESIS_OFFSET                 (78u)
#define key_touch_BUTTON3_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON3_HYSTERESIS_PARAM_ID               (0x6E83004Eu)

#define key_touch_BUTTON3_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button3.onDebounce)
#define key_touch_BUTTON3_ON_DEBOUNCE_OFFSET                (79u)
#define key_touch_BUTTON3_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON3_ON_DEBOUNCE_PARAM_ID              (0x6883004Fu)

#define key_touch_BUTTON3_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button3.lowBslnRst)
#define key_touch_BUTTON3_LOW_BSLN_RST_OFFSET               (80u)
#define key_touch_BUTTON3_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON3_LOW_BSLN_RST_PARAM_ID             (0x64830050u)

#define key_touch_BUTTON3_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button3.bslnCoeff)
#define key_touch_BUTTON3_BSLN_COEFF_OFFSET                 (81u)
#define key_touch_BUTTON3_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON3_BSLN_COEFF_PARAM_ID               (0x62830051u)

#define key_touch_BUTTON3_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button3.idacMod[0u])
#define key_touch_BUTTON3_IDAC_MOD0_OFFSET                  (82u)
#define key_touch_BUTTON3_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON3_IDAC_MOD0_PARAM_ID                (0x4E030052u)

#define key_touch_BUTTON3_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button3.snsClkSource)
#define key_touch_BUTTON3_SNS_CLK_SOURCE_OFFSET             (83u)
#define key_touch_BUTTON3_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON3_SNS_CLK_SOURCE_PARAM_ID           (0x45830053u)

#define key_touch_BUTTON4_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button4.resolution)
#define key_touch_BUTTON4_RESOLUTION_OFFSET                 (84u)
#define key_touch_BUTTON4_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON4_RESOLUTION_PARAM_ID               (0xA4840054u)

#define key_touch_BUTTON4_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button4.fingerTh)
#define key_touch_BUTTON4_FINGER_TH_OFFSET                  (86u)
#define key_touch_BUTTON4_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON4_FINGER_TH_PARAM_ID                (0xA8840056u)

#define key_touch_BUTTON4_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button4.noiseTh)
#define key_touch_BUTTON4_NOISE_TH_OFFSET                   (88u)
#define key_touch_BUTTON4_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON4_NOISE_TH_PARAM_ID                 (0x6F840058u)

#define key_touch_BUTTON4_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button4.nNoiseTh)
#define key_touch_BUTTON4_NNOISE_TH_OFFSET                  (89u)
#define key_touch_BUTTON4_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON4_NNOISE_TH_PARAM_ID                (0x69840059u)

#define key_touch_BUTTON4_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button4.hysteresis)
#define key_touch_BUTTON4_HYSTERESIS_OFFSET                 (90u)
#define key_touch_BUTTON4_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON4_HYSTERESIS_PARAM_ID               (0x6384005Au)

#define key_touch_BUTTON4_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button4.onDebounce)
#define key_touch_BUTTON4_ON_DEBOUNCE_OFFSET                (91u)
#define key_touch_BUTTON4_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON4_ON_DEBOUNCE_PARAM_ID              (0x6584005Bu)

#define key_touch_BUTTON4_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button4.lowBslnRst)
#define key_touch_BUTTON4_LOW_BSLN_RST_OFFSET               (92u)
#define key_touch_BUTTON4_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON4_LOW_BSLN_RST_PARAM_ID             (0x6E84005Cu)

#define key_touch_BUTTON4_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button4.bslnCoeff)
#define key_touch_BUTTON4_BSLN_COEFF_OFFSET                 (93u)
#define key_touch_BUTTON4_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON4_BSLN_COEFF_PARAM_ID               (0x6884005Du)

#define key_touch_BUTTON4_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button4.idacMod[0u])
#define key_touch_BUTTON4_IDAC_MOD0_OFFSET                  (94u)
#define key_touch_BUTTON4_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON4_IDAC_MOD0_PARAM_ID                (0x4404005Eu)

#define key_touch_BUTTON4_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button4.snsClkSource)
#define key_touch_BUTTON4_SNS_CLK_SOURCE_OFFSET             (95u)
#define key_touch_BUTTON4_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON4_SNS_CLK_SOURCE_PARAM_ID           (0x4F84005Fu)

#define key_touch_BUTTON5_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button5.resolution)
#define key_touch_BUTTON5_RESOLUTION_OFFSET                 (96u)
#define key_touch_BUTTON5_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON5_RESOLUTION_PARAM_ID               (0xA9850060u)

#define key_touch_BUTTON5_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button5.fingerTh)
#define key_touch_BUTTON5_FINGER_TH_OFFSET                  (98u)
#define key_touch_BUTTON5_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON5_FINGER_TH_PARAM_ID                (0xA5850062u)

#define key_touch_BUTTON5_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button5.noiseTh)
#define key_touch_BUTTON5_NOISE_TH_OFFSET                   (100u)
#define key_touch_BUTTON5_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON5_NOISE_TH_PARAM_ID                 (0x60850064u)

#define key_touch_BUTTON5_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button5.nNoiseTh)
#define key_touch_BUTTON5_NNOISE_TH_OFFSET                  (101u)
#define key_touch_BUTTON5_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON5_NNOISE_TH_PARAM_ID                (0x66850065u)

#define key_touch_BUTTON5_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button5.hysteresis)
#define key_touch_BUTTON5_HYSTERESIS_OFFSET                 (102u)
#define key_touch_BUTTON5_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON5_HYSTERESIS_PARAM_ID               (0x6C850066u)

#define key_touch_BUTTON5_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button5.onDebounce)
#define key_touch_BUTTON5_ON_DEBOUNCE_OFFSET                (103u)
#define key_touch_BUTTON5_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON5_ON_DEBOUNCE_PARAM_ID              (0x6A850067u)

#define key_touch_BUTTON5_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button5.lowBslnRst)
#define key_touch_BUTTON5_LOW_BSLN_RST_OFFSET               (104u)
#define key_touch_BUTTON5_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON5_LOW_BSLN_RST_PARAM_ID             (0x63850068u)

#define key_touch_BUTTON5_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button5.bslnCoeff)
#define key_touch_BUTTON5_BSLN_COEFF_OFFSET                 (105u)
#define key_touch_BUTTON5_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON5_BSLN_COEFF_PARAM_ID               (0x65850069u)

#define key_touch_BUTTON5_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button5.idacMod[0u])
#define key_touch_BUTTON5_IDAC_MOD0_OFFSET                  (106u)
#define key_touch_BUTTON5_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON5_IDAC_MOD0_PARAM_ID                (0x4905006Au)

#define key_touch_BUTTON5_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button5.snsClkSource)
#define key_touch_BUTTON5_SNS_CLK_SOURCE_OFFSET             (107u)
#define key_touch_BUTTON5_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON5_SNS_CLK_SOURCE_PARAM_ID           (0x4285006Bu)

#define key_touch_BUTTON6_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button6.resolution)
#define key_touch_BUTTON6_RESOLUTION_OFFSET                 (108u)
#define key_touch_BUTTON6_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON6_RESOLUTION_PARAM_ID               (0xAF86006Cu)

#define key_touch_BUTTON6_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button6.fingerTh)
#define key_touch_BUTTON6_FINGER_TH_OFFSET                  (110u)
#define key_touch_BUTTON6_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON6_FINGER_TH_PARAM_ID                (0xA386006Eu)

#define key_touch_BUTTON6_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button6.noiseTh)
#define key_touch_BUTTON6_NOISE_TH_OFFSET                   (112u)
#define key_touch_BUTTON6_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON6_NOISE_TH_PARAM_ID                 (0x61860070u)

#define key_touch_BUTTON6_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button6.nNoiseTh)
#define key_touch_BUTTON6_NNOISE_TH_OFFSET                  (113u)
#define key_touch_BUTTON6_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON6_NNOISE_TH_PARAM_ID                (0x67860071u)

#define key_touch_BUTTON6_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button6.hysteresis)
#define key_touch_BUTTON6_HYSTERESIS_OFFSET                 (114u)
#define key_touch_BUTTON6_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON6_HYSTERESIS_PARAM_ID               (0x6D860072u)

#define key_touch_BUTTON6_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button6.onDebounce)
#define key_touch_BUTTON6_ON_DEBOUNCE_OFFSET                (115u)
#define key_touch_BUTTON6_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON6_ON_DEBOUNCE_PARAM_ID              (0x6B860073u)

#define key_touch_BUTTON6_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button6.lowBslnRst)
#define key_touch_BUTTON6_LOW_BSLN_RST_OFFSET               (116u)
#define key_touch_BUTTON6_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON6_LOW_BSLN_RST_PARAM_ID             (0x60860074u)

#define key_touch_BUTTON6_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button6.bslnCoeff)
#define key_touch_BUTTON6_BSLN_COEFF_OFFSET                 (117u)
#define key_touch_BUTTON6_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON6_BSLN_COEFF_PARAM_ID               (0x66860075u)

#define key_touch_BUTTON6_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button6.idacMod[0u])
#define key_touch_BUTTON6_IDAC_MOD0_OFFSET                  (118u)
#define key_touch_BUTTON6_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON6_IDAC_MOD0_PARAM_ID                (0x4A060076u)

#define key_touch_BUTTON6_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button6.snsClkSource)
#define key_touch_BUTTON6_SNS_CLK_SOURCE_OFFSET             (119u)
#define key_touch_BUTTON6_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON6_SNS_CLK_SOURCE_PARAM_ID           (0x41860077u)

#define key_touch_BUTTON7_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button7.resolution)
#define key_touch_BUTTON7_RESOLUTION_OFFSET                 (120u)
#define key_touch_BUTTON7_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON7_RESOLUTION_PARAM_ID               (0xA8870078u)

#define key_touch_BUTTON7_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button7.fingerTh)
#define key_touch_BUTTON7_FINGER_TH_OFFSET                  (122u)
#define key_touch_BUTTON7_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON7_FINGER_TH_PARAM_ID                (0xA487007Au)

#define key_touch_BUTTON7_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button7.noiseTh)
#define key_touch_BUTTON7_NOISE_TH_OFFSET                   (124u)
#define key_touch_BUTTON7_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON7_NOISE_TH_PARAM_ID                 (0x6187007Cu)

#define key_touch_BUTTON7_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button7.nNoiseTh)
#define key_touch_BUTTON7_NNOISE_TH_OFFSET                  (125u)
#define key_touch_BUTTON7_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON7_NNOISE_TH_PARAM_ID                (0x6787007Du)

#define key_touch_BUTTON7_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button7.hysteresis)
#define key_touch_BUTTON7_HYSTERESIS_OFFSET                 (126u)
#define key_touch_BUTTON7_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON7_HYSTERESIS_PARAM_ID               (0x6D87007Eu)

#define key_touch_BUTTON7_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button7.onDebounce)
#define key_touch_BUTTON7_ON_DEBOUNCE_OFFSET                (127u)
#define key_touch_BUTTON7_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON7_ON_DEBOUNCE_PARAM_ID              (0x6B87007Fu)

#define key_touch_BUTTON7_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button7.lowBslnRst)
#define key_touch_BUTTON7_LOW_BSLN_RST_OFFSET               (128u)
#define key_touch_BUTTON7_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON7_LOW_BSLN_RST_PARAM_ID             (0x63870080u)

#define key_touch_BUTTON7_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button7.bslnCoeff)
#define key_touch_BUTTON7_BSLN_COEFF_OFFSET                 (129u)
#define key_touch_BUTTON7_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON7_BSLN_COEFF_PARAM_ID               (0x65870081u)

#define key_touch_BUTTON7_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button7.idacMod[0u])
#define key_touch_BUTTON7_IDAC_MOD0_OFFSET                  (130u)
#define key_touch_BUTTON7_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON7_IDAC_MOD0_PARAM_ID                (0x49070082u)

#define key_touch_BUTTON7_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button7.snsClkSource)
#define key_touch_BUTTON7_SNS_CLK_SOURCE_OFFSET             (131u)
#define key_touch_BUTTON7_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON7_SNS_CLK_SOURCE_PARAM_ID           (0x42870083u)

#define key_touch_BUTTON8_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button8.resolution)
#define key_touch_BUTTON8_RESOLUTION_OFFSET                 (132u)
#define key_touch_BUTTON8_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON8_RESOLUTION_PARAM_ID               (0xA2880084u)

#define key_touch_BUTTON8_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button8.fingerTh)
#define key_touch_BUTTON8_FINGER_TH_OFFSET                  (134u)
#define key_touch_BUTTON8_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON8_FINGER_TH_PARAM_ID                (0xAE880086u)

#define key_touch_BUTTON8_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button8.noiseTh)
#define key_touch_BUTTON8_NOISE_TH_OFFSET                   (136u)
#define key_touch_BUTTON8_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON8_NOISE_TH_PARAM_ID                 (0x69880088u)

#define key_touch_BUTTON8_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button8.nNoiseTh)
#define key_touch_BUTTON8_NNOISE_TH_OFFSET                  (137u)
#define key_touch_BUTTON8_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON8_NNOISE_TH_PARAM_ID                (0x6F880089u)

#define key_touch_BUTTON8_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button8.hysteresis)
#define key_touch_BUTTON8_HYSTERESIS_OFFSET                 (138u)
#define key_touch_BUTTON8_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON8_HYSTERESIS_PARAM_ID               (0x6588008Au)

#define key_touch_BUTTON8_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button8.onDebounce)
#define key_touch_BUTTON8_ON_DEBOUNCE_OFFSET                (139u)
#define key_touch_BUTTON8_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON8_ON_DEBOUNCE_PARAM_ID              (0x6388008Bu)

#define key_touch_BUTTON8_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button8.lowBslnRst)
#define key_touch_BUTTON8_LOW_BSLN_RST_OFFSET               (140u)
#define key_touch_BUTTON8_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON8_LOW_BSLN_RST_PARAM_ID             (0x6888008Cu)

#define key_touch_BUTTON8_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button8.bslnCoeff)
#define key_touch_BUTTON8_BSLN_COEFF_OFFSET                 (141u)
#define key_touch_BUTTON8_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON8_BSLN_COEFF_PARAM_ID               (0x6E88008Du)

#define key_touch_BUTTON8_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button8.idacMod[0u])
#define key_touch_BUTTON8_IDAC_MOD0_OFFSET                  (142u)
#define key_touch_BUTTON8_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON8_IDAC_MOD0_PARAM_ID                (0x4208008Eu)

#define key_touch_BUTTON8_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button8.snsClkSource)
#define key_touch_BUTTON8_SNS_CLK_SOURCE_OFFSET             (143u)
#define key_touch_BUTTON8_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON8_SNS_CLK_SOURCE_PARAM_ID           (0x4988008Fu)

#define key_touch_BUTTON9_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button9.resolution)
#define key_touch_BUTTON9_RESOLUTION_OFFSET                 (144u)
#define key_touch_BUTTON9_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON9_RESOLUTION_PARAM_ID               (0xA5890090u)

#define key_touch_BUTTON9_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button9.fingerTh)
#define key_touch_BUTTON9_FINGER_TH_OFFSET                  (146u)
#define key_touch_BUTTON9_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON9_FINGER_TH_PARAM_ID                (0xA9890092u)

#define key_touch_BUTTON9_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button9.noiseTh)
#define key_touch_BUTTON9_NOISE_TH_OFFSET                   (148u)
#define key_touch_BUTTON9_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON9_NOISE_TH_PARAM_ID                 (0x6C890094u)

#define key_touch_BUTTON9_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button9.nNoiseTh)
#define key_touch_BUTTON9_NNOISE_TH_OFFSET                  (149u)
#define key_touch_BUTTON9_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON9_NNOISE_TH_PARAM_ID                (0x6A890095u)

#define key_touch_BUTTON9_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button9.hysteresis)
#define key_touch_BUTTON9_HYSTERESIS_OFFSET                 (150u)
#define key_touch_BUTTON9_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON9_HYSTERESIS_PARAM_ID               (0x60890096u)

#define key_touch_BUTTON9_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button9.onDebounce)
#define key_touch_BUTTON9_ON_DEBOUNCE_OFFSET                (151u)
#define key_touch_BUTTON9_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON9_ON_DEBOUNCE_PARAM_ID              (0x66890097u)

#define key_touch_BUTTON9_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button9.lowBslnRst)
#define key_touch_BUTTON9_LOW_BSLN_RST_OFFSET               (152u)
#define key_touch_BUTTON9_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON9_LOW_BSLN_RST_PARAM_ID             (0x6F890098u)

#define key_touch_BUTTON9_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button9.bslnCoeff)
#define key_touch_BUTTON9_BSLN_COEFF_OFFSET                 (153u)
#define key_touch_BUTTON9_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON9_BSLN_COEFF_PARAM_ID               (0x69890099u)

#define key_touch_BUTTON9_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button9.idacMod[0u])
#define key_touch_BUTTON9_IDAC_MOD0_OFFSET                  (154u)
#define key_touch_BUTTON9_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON9_IDAC_MOD0_PARAM_ID                (0x4509009Au)

#define key_touch_BUTTON9_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button9.snsClkSource)
#define key_touch_BUTTON9_SNS_CLK_SOURCE_OFFSET             (155u)
#define key_touch_BUTTON9_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON9_SNS_CLK_SOURCE_PARAM_ID           (0x4E89009Bu)

#define key_touch_BUTTON10_RESOLUTION_VALUE                 (key_touch_dsRam.wdgtList.button10.resolution)
#define key_touch_BUTTON10_RESOLUTION_OFFSET                (156u)
#define key_touch_BUTTON10_RESOLUTION_SIZE                  (2u)
#define key_touch_BUTTON10_RESOLUTION_PARAM_ID              (0xA38A009Cu)

#define key_touch_BUTTON10_FINGER_TH_VALUE                  (key_touch_dsRam.wdgtList.button10.fingerTh)
#define key_touch_BUTTON10_FINGER_TH_OFFSET                 (158u)
#define key_touch_BUTTON10_FINGER_TH_SIZE                   (2u)
#define key_touch_BUTTON10_FINGER_TH_PARAM_ID               (0xAF8A009Eu)

#define key_touch_BUTTON10_NOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button10.noiseTh)
#define key_touch_BUTTON10_NOISE_TH_OFFSET                  (160u)
#define key_touch_BUTTON10_NOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON10_NOISE_TH_PARAM_ID                (0x678A00A0u)

#define key_touch_BUTTON10_NNOISE_TH_VALUE                  (key_touch_dsRam.wdgtList.button10.nNoiseTh)
#define key_touch_BUTTON10_NNOISE_TH_OFFSET                 (161u)
#define key_touch_BUTTON10_NNOISE_TH_SIZE                   (1u)
#define key_touch_BUTTON10_NNOISE_TH_PARAM_ID               (0x618A00A1u)

#define key_touch_BUTTON10_HYSTERESIS_VALUE                 (key_touch_dsRam.wdgtList.button10.hysteresis)
#define key_touch_BUTTON10_HYSTERESIS_OFFSET                (162u)
#define key_touch_BUTTON10_HYSTERESIS_SIZE                  (1u)
#define key_touch_BUTTON10_HYSTERESIS_PARAM_ID              (0x6B8A00A2u)

#define key_touch_BUTTON10_ON_DEBOUNCE_VALUE                (key_touch_dsRam.wdgtList.button10.onDebounce)
#define key_touch_BUTTON10_ON_DEBOUNCE_OFFSET               (163u)
#define key_touch_BUTTON10_ON_DEBOUNCE_SIZE                 (1u)
#define key_touch_BUTTON10_ON_DEBOUNCE_PARAM_ID             (0x6D8A00A3u)

#define key_touch_BUTTON10_LOW_BSLN_RST_VALUE               (key_touch_dsRam.wdgtList.button10.lowBslnRst)
#define key_touch_BUTTON10_LOW_BSLN_RST_OFFSET              (164u)
#define key_touch_BUTTON10_LOW_BSLN_RST_SIZE                (1u)
#define key_touch_BUTTON10_LOW_BSLN_RST_PARAM_ID            (0x668A00A4u)

#define key_touch_BUTTON10_BSLN_COEFF_VALUE                 (key_touch_dsRam.wdgtList.button10.bslnCoeff)
#define key_touch_BUTTON10_BSLN_COEFF_OFFSET                (165u)
#define key_touch_BUTTON10_BSLN_COEFF_SIZE                  (1u)
#define key_touch_BUTTON10_BSLN_COEFF_PARAM_ID              (0x608A00A5u)

#define key_touch_BUTTON10_IDAC_MOD0_VALUE                  (key_touch_dsRam.wdgtList.button10.idacMod[0u])
#define key_touch_BUTTON10_IDAC_MOD0_OFFSET                 (166u)
#define key_touch_BUTTON10_IDAC_MOD0_SIZE                   (1u)
#define key_touch_BUTTON10_IDAC_MOD0_PARAM_ID               (0x4C0A00A6u)

#define key_touch_BUTTON10_SNS_CLK_SOURCE_VALUE             (key_touch_dsRam.wdgtList.button10.snsClkSource)
#define key_touch_BUTTON10_SNS_CLK_SOURCE_OFFSET            (167u)
#define key_touch_BUTTON10_SNS_CLK_SOURCE_SIZE              (1u)
#define key_touch_BUTTON10_SNS_CLK_SOURCE_PARAM_ID          (0x478A00A7u)

#define key_touch_BUTTON11_RESOLUTION_VALUE                 (key_touch_dsRam.wdgtList.button11.resolution)
#define key_touch_BUTTON11_RESOLUTION_OFFSET                (168u)
#define key_touch_BUTTON11_RESOLUTION_SIZE                  (2u)
#define key_touch_BUTTON11_RESOLUTION_PARAM_ID              (0xAE8B00A8u)

#define key_touch_BUTTON11_FINGER_TH_VALUE                  (key_touch_dsRam.wdgtList.button11.fingerTh)
#define key_touch_BUTTON11_FINGER_TH_OFFSET                 (170u)
#define key_touch_BUTTON11_FINGER_TH_SIZE                   (2u)
#define key_touch_BUTTON11_FINGER_TH_PARAM_ID               (0xA28B00AAu)

#define key_touch_BUTTON11_NOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button11.noiseTh)
#define key_touch_BUTTON11_NOISE_TH_OFFSET                  (172u)
#define key_touch_BUTTON11_NOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON11_NOISE_TH_PARAM_ID                (0x678B00ACu)

#define key_touch_BUTTON11_NNOISE_TH_VALUE                  (key_touch_dsRam.wdgtList.button11.nNoiseTh)
#define key_touch_BUTTON11_NNOISE_TH_OFFSET                 (173u)
#define key_touch_BUTTON11_NNOISE_TH_SIZE                   (1u)
#define key_touch_BUTTON11_NNOISE_TH_PARAM_ID               (0x618B00ADu)

#define key_touch_BUTTON11_HYSTERESIS_VALUE                 (key_touch_dsRam.wdgtList.button11.hysteresis)
#define key_touch_BUTTON11_HYSTERESIS_OFFSET                (174u)
#define key_touch_BUTTON11_HYSTERESIS_SIZE                  (1u)
#define key_touch_BUTTON11_HYSTERESIS_PARAM_ID              (0x6B8B00AEu)

#define key_touch_BUTTON11_ON_DEBOUNCE_VALUE                (key_touch_dsRam.wdgtList.button11.onDebounce)
#define key_touch_BUTTON11_ON_DEBOUNCE_OFFSET               (175u)
#define key_touch_BUTTON11_ON_DEBOUNCE_SIZE                 (1u)
#define key_touch_BUTTON11_ON_DEBOUNCE_PARAM_ID             (0x6D8B00AFu)

#define key_touch_BUTTON11_LOW_BSLN_RST_VALUE               (key_touch_dsRam.wdgtList.button11.lowBslnRst)
#define key_touch_BUTTON11_LOW_BSLN_RST_OFFSET              (176u)
#define key_touch_BUTTON11_LOW_BSLN_RST_SIZE                (1u)
#define key_touch_BUTTON11_LOW_BSLN_RST_PARAM_ID            (0x618B00B0u)

#define key_touch_BUTTON11_BSLN_COEFF_VALUE                 (key_touch_dsRam.wdgtList.button11.bslnCoeff)
#define key_touch_BUTTON11_BSLN_COEFF_OFFSET                (177u)
#define key_touch_BUTTON11_BSLN_COEFF_SIZE                  (1u)
#define key_touch_BUTTON11_BSLN_COEFF_PARAM_ID              (0x678B00B1u)

#define key_touch_BUTTON11_IDAC_MOD0_VALUE                  (key_touch_dsRam.wdgtList.button11.idacMod[0u])
#define key_touch_BUTTON11_IDAC_MOD0_OFFSET                 (178u)
#define key_touch_BUTTON11_IDAC_MOD0_SIZE                   (1u)
#define key_touch_BUTTON11_IDAC_MOD0_PARAM_ID               (0x4B0B00B2u)

#define key_touch_BUTTON11_SNS_CLK_SOURCE_VALUE             (key_touch_dsRam.wdgtList.button11.snsClkSource)
#define key_touch_BUTTON11_SNS_CLK_SOURCE_OFFSET            (179u)
#define key_touch_BUTTON11_SNS_CLK_SOURCE_SIZE              (1u)
#define key_touch_BUTTON11_SNS_CLK_SOURCE_PARAM_ID          (0x408B00B3u)

#define key_touch_BUTTON0_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button0[0u].raw[0u])
#define key_touch_BUTTON0_SNS0_RAW0_OFFSET                  (180u)
#define key_touch_BUTTON0_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON0_SNS0_RAW0_PARAM_ID                (0x8A0000B4u)

#define key_touch_BUTTON0_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button0[0u].bsln[0u])
#define key_touch_BUTTON0_SNS0_BSLN0_OFFSET                 (182u)
#define key_touch_BUTTON0_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON0_SNS0_BSLN0_PARAM_ID               (0x860000B6u)

#define key_touch_BUTTON0_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button0[0u].bslnExt[0u])
#define key_touch_BUTTON0_SNS0_BSLN_EXT0_OFFSET             (184u)
#define key_touch_BUTTON0_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON0_SNS0_BSLN_EXT0_PARAM_ID           (0x410000B8u)

#define key_touch_BUTTON0_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button0[0u].diff)
#define key_touch_BUTTON0_SNS0_DIFF_OFFSET                  (186u)
#define key_touch_BUTTON0_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON0_SNS0_DIFF_PARAM_ID                (0x850000BAu)

#define key_touch_BUTTON0_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button0[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON0_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (188u)
#define key_touch_BUTTON0_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON0_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x400000BCu)

#define key_touch_BUTTON0_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button0[0u].idacComp[0u])
#define key_touch_BUTTON0_SNS0_IDAC_COMP0_OFFSET            (189u)
#define key_touch_BUTTON0_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON0_SNS0_IDAC_COMP0_PARAM_ID          (0x460000BDu)

#define key_touch_BUTTON1_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button1[0u].raw[0u])
#define key_touch_BUTTON1_SNS0_RAW0_OFFSET                  (190u)
#define key_touch_BUTTON1_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON1_SNS0_RAW0_PARAM_ID                (0x840000BEu)

#define key_touch_BUTTON1_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button1[0u].bsln[0u])
#define key_touch_BUTTON1_SNS0_BSLN0_OFFSET                 (192u)
#define key_touch_BUTTON1_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON1_SNS0_BSLN0_PARAM_ID               (0x890000C0u)

#define key_touch_BUTTON1_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button1[0u].bslnExt[0u])
#define key_touch_BUTTON1_SNS0_BSLN_EXT0_OFFSET             (194u)
#define key_touch_BUTTON1_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON1_SNS0_BSLN_EXT0_PARAM_ID           (0x4D0000C2u)

#define key_touch_BUTTON1_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button1[0u].diff)
#define key_touch_BUTTON1_SNS0_DIFF_OFFSET                  (196u)
#define key_touch_BUTTON1_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON1_SNS0_DIFF_PARAM_ID                (0x880000C4u)

#define key_touch_BUTTON1_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button1[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON1_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (198u)
#define key_touch_BUTTON1_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON1_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4C0000C6u)

#define key_touch_BUTTON1_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button1[0u].idacComp[0u])
#define key_touch_BUTTON1_SNS0_IDAC_COMP0_OFFSET            (199u)
#define key_touch_BUTTON1_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON1_SNS0_IDAC_COMP0_PARAM_ID          (0x4A0000C7u)

#define key_touch_BUTTON2_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button2[0u].raw[0u])
#define key_touch_BUTTON2_SNS0_RAW0_OFFSET                  (200u)
#define key_touch_BUTTON2_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON2_SNS0_RAW0_PARAM_ID                (0x8B0000C8u)

#define key_touch_BUTTON2_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button2[0u].bsln[0u])
#define key_touch_BUTTON2_SNS0_BSLN0_OFFSET                 (202u)
#define key_touch_BUTTON2_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON2_SNS0_BSLN0_PARAM_ID               (0x870000CAu)

#define key_touch_BUTTON2_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button2[0u].bslnExt[0u])
#define key_touch_BUTTON2_SNS0_BSLN_EXT0_OFFSET             (204u)
#define key_touch_BUTTON2_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON2_SNS0_BSLN_EXT0_PARAM_ID           (0x420000CCu)

#define key_touch_BUTTON2_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button2[0u].diff)
#define key_touch_BUTTON2_SNS0_DIFF_OFFSET                  (206u)
#define key_touch_BUTTON2_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON2_SNS0_DIFF_PARAM_ID                (0x860000CEu)

#define key_touch_BUTTON2_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button2[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON2_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (208u)
#define key_touch_BUTTON2_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON2_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x440000D0u)

#define key_touch_BUTTON2_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button2[0u].idacComp[0u])
#define key_touch_BUTTON2_SNS0_IDAC_COMP0_OFFSET            (209u)
#define key_touch_BUTTON2_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON2_SNS0_IDAC_COMP0_PARAM_ID          (0x420000D1u)

#define key_touch_BUTTON3_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button3[0u].raw[0u])
#define key_touch_BUTTON3_SNS0_RAW0_OFFSET                  (210u)
#define key_touch_BUTTON3_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON3_SNS0_RAW0_PARAM_ID                (0x800000D2u)

#define key_touch_BUTTON3_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button3[0u].bsln[0u])
#define key_touch_BUTTON3_SNS0_BSLN0_OFFSET                 (212u)
#define key_touch_BUTTON3_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON3_SNS0_BSLN0_PARAM_ID               (0x8D0000D4u)

#define key_touch_BUTTON3_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button3[0u].bslnExt[0u])
#define key_touch_BUTTON3_SNS0_BSLN_EXT0_OFFSET             (214u)
#define key_touch_BUTTON3_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON3_SNS0_BSLN_EXT0_PARAM_ID           (0x490000D6u)

#define key_touch_BUTTON3_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button3[0u].diff)
#define key_touch_BUTTON3_SNS0_DIFF_OFFSET                  (216u)
#define key_touch_BUTTON3_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON3_SNS0_DIFF_PARAM_ID                (0x8E0000D8u)

#define key_touch_BUTTON3_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button3[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON3_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (218u)
#define key_touch_BUTTON3_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON3_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4A0000DAu)

#define key_touch_BUTTON3_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button3[0u].idacComp[0u])
#define key_touch_BUTTON3_SNS0_IDAC_COMP0_OFFSET            (219u)
#define key_touch_BUTTON3_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON3_SNS0_IDAC_COMP0_PARAM_ID          (0x4C0000DBu)

#define key_touch_BUTTON4_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button4[0u].raw[0u])
#define key_touch_BUTTON4_SNS0_RAW0_OFFSET                  (220u)
#define key_touch_BUTTON4_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON4_SNS0_RAW0_PARAM_ID                (0x8F0000DCu)

#define key_touch_BUTTON4_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button4[0u].bsln[0u])
#define key_touch_BUTTON4_SNS0_BSLN0_OFFSET                 (222u)
#define key_touch_BUTTON4_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON4_SNS0_BSLN0_PARAM_ID               (0x830000DEu)

#define key_touch_BUTTON4_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button4[0u].bslnExt[0u])
#define key_touch_BUTTON4_SNS0_BSLN_EXT0_OFFSET             (224u)
#define key_touch_BUTTON4_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON4_SNS0_BSLN_EXT0_PARAM_ID           (0x4B0000E0u)

#define key_touch_BUTTON4_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button4[0u].diff)
#define key_touch_BUTTON4_SNS0_DIFF_OFFSET                  (226u)
#define key_touch_BUTTON4_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON4_SNS0_DIFF_PARAM_ID                (0x8F0000E2u)

#define key_touch_BUTTON4_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button4[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON4_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (228u)
#define key_touch_BUTTON4_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON4_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4A0000E4u)

#define key_touch_BUTTON4_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button4[0u].idacComp[0u])
#define key_touch_BUTTON4_SNS0_IDAC_COMP0_OFFSET            (229u)
#define key_touch_BUTTON4_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON4_SNS0_IDAC_COMP0_PARAM_ID          (0x4C0000E5u)

#define key_touch_BUTTON5_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button5[0u].raw[0u])
#define key_touch_BUTTON5_SNS0_RAW0_OFFSET                  (230u)
#define key_touch_BUTTON5_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON5_SNS0_RAW0_PARAM_ID                (0x8E0000E6u)

#define key_touch_BUTTON5_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button5[0u].bsln[0u])
#define key_touch_BUTTON5_SNS0_BSLN0_OFFSET                 (232u)
#define key_touch_BUTTON5_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON5_SNS0_BSLN0_PARAM_ID               (0x810000E8u)

#define key_touch_BUTTON5_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button5[0u].bslnExt[0u])
#define key_touch_BUTTON5_SNS0_BSLN_EXT0_OFFSET             (234u)
#define key_touch_BUTTON5_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON5_SNS0_BSLN_EXT0_PARAM_ID           (0x450000EAu)

#define key_touch_BUTTON5_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button5[0u].diff)
#define key_touch_BUTTON5_SNS0_DIFF_OFFSET                  (236u)
#define key_touch_BUTTON5_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON5_SNS0_DIFF_PARAM_ID                (0x800000ECu)

#define key_touch_BUTTON5_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button5[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON5_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (238u)
#define key_touch_BUTTON5_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON5_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x440000EEu)

#define key_touch_BUTTON5_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button5[0u].idacComp[0u])
#define key_touch_BUTTON5_SNS0_IDAC_COMP0_OFFSET            (239u)
#define key_touch_BUTTON5_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON5_SNS0_IDAC_COMP0_PARAM_ID          (0x420000EFu)

#define key_touch_BUTTON6_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button6[0u].raw[0u])
#define key_touch_BUTTON6_SNS0_RAW0_OFFSET                  (240u)
#define key_touch_BUTTON6_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON6_SNS0_RAW0_PARAM_ID                (0x860000F0u)

#define key_touch_BUTTON6_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button6[0u].bsln[0u])
#define key_touch_BUTTON6_SNS0_BSLN0_OFFSET                 (242u)
#define key_touch_BUTTON6_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON6_SNS0_BSLN0_PARAM_ID               (0x8A0000F2u)

#define key_touch_BUTTON6_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button6[0u].bslnExt[0u])
#define key_touch_BUTTON6_SNS0_BSLN_EXT0_OFFSET             (244u)
#define key_touch_BUTTON6_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON6_SNS0_BSLN_EXT0_PARAM_ID           (0x4F0000F4u)

#define key_touch_BUTTON6_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button6[0u].diff)
#define key_touch_BUTTON6_SNS0_DIFF_OFFSET                  (246u)
#define key_touch_BUTTON6_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON6_SNS0_DIFF_PARAM_ID                (0x8B0000F6u)

#define key_touch_BUTTON6_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button6[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON6_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (248u)
#define key_touch_BUTTON6_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON6_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4C0000F8u)

#define key_touch_BUTTON6_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button6[0u].idacComp[0u])
#define key_touch_BUTTON6_SNS0_IDAC_COMP0_OFFSET            (249u)
#define key_touch_BUTTON6_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON6_SNS0_IDAC_COMP0_PARAM_ID          (0x4A0000F9u)

#define key_touch_BUTTON7_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button7[0u].raw[0u])
#define key_touch_BUTTON7_SNS0_RAW0_OFFSET                  (250u)
#define key_touch_BUTTON7_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON7_SNS0_RAW0_PARAM_ID                (0x880000FAu)

#define key_touch_BUTTON7_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button7[0u].bsln[0u])
#define key_touch_BUTTON7_SNS0_BSLN0_OFFSET                 (252u)
#define key_touch_BUTTON7_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON7_SNS0_BSLN0_PARAM_ID               (0x850000FCu)

#define key_touch_BUTTON7_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button7[0u].bslnExt[0u])
#define key_touch_BUTTON7_SNS0_BSLN_EXT0_OFFSET             (254u)
#define key_touch_BUTTON7_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON7_SNS0_BSLN_EXT0_PARAM_ID           (0x410000FEu)

#define key_touch_BUTTON7_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button7[0u].diff)
#define key_touch_BUTTON7_SNS0_DIFF_OFFSET                  (256u)
#define key_touch_BUTTON7_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON7_SNS0_DIFF_PARAM_ID                (0x8C000100u)

#define key_touch_BUTTON7_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button7[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON7_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (258u)
#define key_touch_BUTTON7_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON7_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x48000102u)

#define key_touch_BUTTON7_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button7[0u].idacComp[0u])
#define key_touch_BUTTON7_SNS0_IDAC_COMP0_OFFSET            (259u)
#define key_touch_BUTTON7_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON7_SNS0_IDAC_COMP0_PARAM_ID          (0x4E000103u)

#define key_touch_BUTTON8_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button8[0u].raw[0u])
#define key_touch_BUTTON8_SNS0_RAW0_OFFSET                  (260u)
#define key_touch_BUTTON8_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON8_SNS0_RAW0_PARAM_ID                (0x8D000104u)

#define key_touch_BUTTON8_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button8[0u].bsln[0u])
#define key_touch_BUTTON8_SNS0_BSLN0_OFFSET                 (262u)
#define key_touch_BUTTON8_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON8_SNS0_BSLN0_PARAM_ID               (0x81000106u)

#define key_touch_BUTTON8_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button8[0u].bslnExt[0u])
#define key_touch_BUTTON8_SNS0_BSLN_EXT0_OFFSET             (264u)
#define key_touch_BUTTON8_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON8_SNS0_BSLN_EXT0_PARAM_ID           (0x46000108u)

#define key_touch_BUTTON8_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button8[0u].diff)
#define key_touch_BUTTON8_SNS0_DIFF_OFFSET                  (266u)
#define key_touch_BUTTON8_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON8_SNS0_DIFF_PARAM_ID                (0x8200010Au)

#define key_touch_BUTTON8_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button8[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON8_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (268u)
#define key_touch_BUTTON8_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON8_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4700010Cu)

#define key_touch_BUTTON8_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button8[0u].idacComp[0u])
#define key_touch_BUTTON8_SNS0_IDAC_COMP0_OFFSET            (269u)
#define key_touch_BUTTON8_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON8_SNS0_IDAC_COMP0_PARAM_ID          (0x4100010Du)

#define key_touch_BUTTON9_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button9[0u].raw[0u])
#define key_touch_BUTTON9_SNS0_RAW0_OFFSET                  (270u)
#define key_touch_BUTTON9_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON9_SNS0_RAW0_PARAM_ID                (0x8300010Eu)

#define key_touch_BUTTON9_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button9[0u].bsln[0u])
#define key_touch_BUTTON9_SNS0_BSLN0_OFFSET                 (272u)
#define key_touch_BUTTON9_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON9_SNS0_BSLN0_PARAM_ID               (0x89000110u)

#define key_touch_BUTTON9_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button9[0u].bslnExt[0u])
#define key_touch_BUTTON9_SNS0_BSLN_EXT0_OFFSET             (274u)
#define key_touch_BUTTON9_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON9_SNS0_BSLN_EXT0_PARAM_ID           (0x4D000112u)

#define key_touch_BUTTON9_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button9[0u].diff)
#define key_touch_BUTTON9_SNS0_DIFF_OFFSET                  (276u)
#define key_touch_BUTTON9_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON9_SNS0_DIFF_PARAM_ID                (0x88000114u)

#define key_touch_BUTTON9_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button9[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON9_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (278u)
#define key_touch_BUTTON9_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON9_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4C000116u)

#define key_touch_BUTTON9_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button9[0u].idacComp[0u])
#define key_touch_BUTTON9_SNS0_IDAC_COMP0_OFFSET            (279u)
#define key_touch_BUTTON9_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON9_SNS0_IDAC_COMP0_PARAM_ID          (0x4A000117u)

#define key_touch_BUTTON10_SNS0_RAW0_VALUE                  (key_touch_dsRam.snsList.button10[0u].raw[0u])
#define key_touch_BUTTON10_SNS0_RAW0_OFFSET                 (280u)
#define key_touch_BUTTON10_SNS0_RAW0_SIZE                   (2u)
#define key_touch_BUTTON10_SNS0_RAW0_PARAM_ID               (0x8B000118u)

#define key_touch_BUTTON10_SNS0_BSLN0_VALUE                 (key_touch_dsRam.snsList.button10[0u].bsln[0u])
#define key_touch_BUTTON10_SNS0_BSLN0_OFFSET                (282u)
#define key_touch_BUTTON10_SNS0_BSLN0_SIZE                  (2u)
#define key_touch_BUTTON10_SNS0_BSLN0_PARAM_ID              (0x8700011Au)

#define key_touch_BUTTON10_SNS0_BSLN_EXT0_VALUE             (key_touch_dsRam.snsList.button10[0u].bslnExt[0u])
#define key_touch_BUTTON10_SNS0_BSLN_EXT0_OFFSET            (284u)
#define key_touch_BUTTON10_SNS0_BSLN_EXT0_SIZE              (1u)
#define key_touch_BUTTON10_SNS0_BSLN_EXT0_PARAM_ID          (0x4200011Cu)

#define key_touch_BUTTON10_SNS0_DIFF_VALUE                  (key_touch_dsRam.snsList.button10[0u].diff)
#define key_touch_BUTTON10_SNS0_DIFF_OFFSET                 (286u)
#define key_touch_BUTTON10_SNS0_DIFF_SIZE                   (2u)
#define key_touch_BUTTON10_SNS0_DIFF_PARAM_ID               (0x8600011Eu)

#define key_touch_BUTTON10_SNS0_NEG_BSLN_RST_CNT0_VALUE     (key_touch_dsRam.snsList.button10[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON10_SNS0_NEG_BSLN_RST_CNT0_OFFSET    (288u)
#define key_touch_BUTTON10_SNS0_NEG_BSLN_RST_CNT0_SIZE      (1u)
#define key_touch_BUTTON10_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID  (0x4E000120u)

#define key_touch_BUTTON10_SNS0_IDAC_COMP0_VALUE            (key_touch_dsRam.snsList.button10[0u].idacComp[0u])
#define key_touch_BUTTON10_SNS0_IDAC_COMP0_OFFSET           (289u)
#define key_touch_BUTTON10_SNS0_IDAC_COMP0_SIZE             (1u)
#define key_touch_BUTTON10_SNS0_IDAC_COMP0_PARAM_ID         (0x48000121u)

#define key_touch_BUTTON11_SNS0_RAW0_VALUE                  (key_touch_dsRam.snsList.button11[0u].raw[0u])
#define key_touch_BUTTON11_SNS0_RAW0_OFFSET                 (290u)
#define key_touch_BUTTON11_SNS0_RAW0_SIZE                   (2u)
#define key_touch_BUTTON11_SNS0_RAW0_PARAM_ID               (0x8A000122u)

#define key_touch_BUTTON11_SNS0_BSLN0_VALUE                 (key_touch_dsRam.snsList.button11[0u].bsln[0u])
#define key_touch_BUTTON11_SNS0_BSLN0_OFFSET                (292u)
#define key_touch_BUTTON11_SNS0_BSLN0_SIZE                  (2u)
#define key_touch_BUTTON11_SNS0_BSLN0_PARAM_ID              (0x87000124u)

#define key_touch_BUTTON11_SNS0_BSLN_EXT0_VALUE             (key_touch_dsRam.snsList.button11[0u].bslnExt[0u])
#define key_touch_BUTTON11_SNS0_BSLN_EXT0_OFFSET            (294u)
#define key_touch_BUTTON11_SNS0_BSLN_EXT0_SIZE              (1u)
#define key_touch_BUTTON11_SNS0_BSLN_EXT0_PARAM_ID          (0x43000126u)

#define key_touch_BUTTON11_SNS0_DIFF_VALUE                  (key_touch_dsRam.snsList.button11[0u].diff)
#define key_touch_BUTTON11_SNS0_DIFF_OFFSET                 (296u)
#define key_touch_BUTTON11_SNS0_DIFF_SIZE                   (2u)
#define key_touch_BUTTON11_SNS0_DIFF_PARAM_ID               (0x84000128u)

#define key_touch_BUTTON11_SNS0_NEG_BSLN_RST_CNT0_VALUE     (key_touch_dsRam.snsList.button11[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON11_SNS0_NEG_BSLN_RST_CNT0_OFFSET    (298u)
#define key_touch_BUTTON11_SNS0_NEG_BSLN_RST_CNT0_SIZE      (1u)
#define key_touch_BUTTON11_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID  (0x4000012Au)

#define key_touch_BUTTON11_SNS0_IDAC_COMP0_VALUE            (key_touch_dsRam.snsList.button11[0u].idacComp[0u])
#define key_touch_BUTTON11_SNS0_IDAC_COMP0_OFFSET           (299u)
#define key_touch_BUTTON11_SNS0_IDAC_COMP0_SIZE             (1u)
#define key_touch_BUTTON11_SNS0_IDAC_COMP0_PARAM_ID         (0x4600012Bu)

#define key_touch_SNR_TEST_WIDGET_ID_VALUE                  (key_touch_dsRam.snrTestWidgetId)
#define key_touch_SNR_TEST_WIDGET_ID_OFFSET                 (300u)
#define key_touch_SNR_TEST_WIDGET_ID_SIZE                   (1u)
#define key_touch_SNR_TEST_WIDGET_ID_PARAM_ID               (0x6600012Cu)

#define key_touch_SNR_TEST_SENSOR_ID_VALUE                  (key_touch_dsRam.snrTestSensorId)
#define key_touch_SNR_TEST_SENSOR_ID_OFFSET                 (301u)
#define key_touch_SNR_TEST_SENSOR_ID_SIZE                   (1u)
#define key_touch_SNR_TEST_SENSOR_ID_PARAM_ID               (0x6000012Du)

#define key_touch_SNR_TEST_SCAN_COUNTER_VALUE               (key_touch_dsRam.snrTestScanCounter)
#define key_touch_SNR_TEST_SCAN_COUNTER_OFFSET              (302u)
#define key_touch_SNR_TEST_SCAN_COUNTER_SIZE                (2u)
#define key_touch_SNR_TEST_SCAN_COUNTER_PARAM_ID            (0x8900012Eu)

#define key_touch_SNR_TEST_RAW_COUNT0_VALUE                 (key_touch_dsRam.snrTestRawCount[0u])
#define key_touch_SNR_TEST_RAW_COUNT0_OFFSET                (304u)
#define key_touch_SNR_TEST_RAW_COUNT0_SIZE                  (2u)
#define key_touch_SNR_TEST_RAW_COUNT0_PARAM_ID              (0x83000130u)


/*****************************************************************************/
/* Flash Data structure register definitions                                 */
/*****************************************************************************/
#define key_touch_BUTTON0_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[0].ptr2SnsFlash)
#define key_touch_BUTTON0_PTR2SNS_FLASH_OFFSET              (0u)
#define key_touch_BUTTON0_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON0_PTR2SNS_FLASH_PARAM_ID            (0xD1000000u)

#define key_touch_BUTTON0_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[0].ptr2WdgtRam)
#define key_touch_BUTTON0_PTR2WD_RAM_OFFSET                 (4u)
#define key_touch_BUTTON0_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON0_PTR2WD_RAM_PARAM_ID               (0xD0000004u)

#define key_touch_BUTTON0_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[0].ptr2SnsRam)
#define key_touch_BUTTON0_PTR2SNS_RAM_OFFSET                (8u)
#define key_touch_BUTTON0_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON0_PTR2SNS_RAM_PARAM_ID              (0xD3000008u)

#define key_touch_BUTTON0_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[0].ptr2FltrHistory)
#define key_touch_BUTTON0_PTR2FLTR_HISTORY_OFFSET           (12u)
#define key_touch_BUTTON0_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON0_PTR2FLTR_HISTORY_PARAM_ID         (0xD200000Cu)

#define key_touch_BUTTON0_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[0].ptr2DebounceArr)
#define key_touch_BUTTON0_PTR2DEBOUNCE_OFFSET               (16u)
#define key_touch_BUTTON0_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON0_PTR2DEBOUNCE_PARAM_ID             (0xD4000010u)

#define key_touch_BUTTON0_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[0].staticConfig)
#define key_touch_BUTTON0_STATIC_CONFIG_OFFSET              (20u)
#define key_touch_BUTTON0_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON0_STATIC_CONFIG_PARAM_ID            (0x9A000014u)

#define key_touch_BUTTON0_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[0].totalNumSns)
#define key_touch_BUTTON0_TOTAL_NUM_SNS_OFFSET              (22u)
#define key_touch_BUTTON0_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON0_TOTAL_NUM_SNS_PARAM_ID            (0x96000016u)

#define key_touch_BUTTON0_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[0].wdgtType)
#define key_touch_BUTTON0_TYPE_OFFSET                       (24u)
#define key_touch_BUTTON0_TYPE_SIZE                         (1u)
#define key_touch_BUTTON0_TYPE_PARAM_ID                     (0x51000018u)

#define key_touch_BUTTON0_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[0].numCols)
#define key_touch_BUTTON0_NUM_COLS_OFFSET                   (25u)
#define key_touch_BUTTON0_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON0_NUM_COLS_PARAM_ID                 (0x57000019u)

#define key_touch_BUTTON1_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[1].ptr2SnsFlash)
#define key_touch_BUTTON1_PTR2SNS_FLASH_OFFSET              (28u)
#define key_touch_BUTTON1_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON1_PTR2SNS_FLASH_PARAM_ID            (0xD401001Cu)

#define key_touch_BUTTON1_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[1].ptr2WdgtRam)
#define key_touch_BUTTON1_PTR2WD_RAM_OFFSET                 (32u)
#define key_touch_BUTTON1_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON1_PTR2WD_RAM_PARAM_ID               (0xD8010020u)

#define key_touch_BUTTON1_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[1].ptr2SnsRam)
#define key_touch_BUTTON1_PTR2SNS_RAM_OFFSET                (36u)
#define key_touch_BUTTON1_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON1_PTR2SNS_RAM_PARAM_ID              (0xD9010024u)

#define key_touch_BUTTON1_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[1].ptr2FltrHistory)
#define key_touch_BUTTON1_PTR2FLTR_HISTORY_OFFSET           (40u)
#define key_touch_BUTTON1_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON1_PTR2FLTR_HISTORY_PARAM_ID         (0xDA010028u)

#define key_touch_BUTTON1_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[1].ptr2DebounceArr)
#define key_touch_BUTTON1_PTR2DEBOUNCE_OFFSET               (44u)
#define key_touch_BUTTON1_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON1_PTR2DEBOUNCE_PARAM_ID             (0xDB01002Cu)

#define key_touch_BUTTON1_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[1].staticConfig)
#define key_touch_BUTTON1_STATIC_CONFIG_OFFSET              (48u)
#define key_touch_BUTTON1_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON1_STATIC_CONFIG_PARAM_ID            (0x92010030u)

#define key_touch_BUTTON1_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[1].totalNumSns)
#define key_touch_BUTTON1_TOTAL_NUM_SNS_OFFSET              (50u)
#define key_touch_BUTTON1_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON1_TOTAL_NUM_SNS_PARAM_ID            (0x9E010032u)

#define key_touch_BUTTON1_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[1].wdgtType)
#define key_touch_BUTTON1_TYPE_OFFSET                       (52u)
#define key_touch_BUTTON1_TYPE_SIZE                         (1u)
#define key_touch_BUTTON1_TYPE_PARAM_ID                     (0x5B010034u)

#define key_touch_BUTTON1_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[1].numCols)
#define key_touch_BUTTON1_NUM_COLS_OFFSET                   (53u)
#define key_touch_BUTTON1_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON1_NUM_COLS_PARAM_ID                 (0x5D010035u)

#define key_touch_BUTTON2_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[2].ptr2SnsFlash)
#define key_touch_BUTTON2_PTR2SNS_FLASH_OFFSET              (56u)
#define key_touch_BUTTON2_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON2_PTR2SNS_FLASH_PARAM_ID            (0xDA020038u)

#define key_touch_BUTTON2_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[2].ptr2WdgtRam)
#define key_touch_BUTTON2_PTR2WD_RAM_OFFSET                 (60u)
#define key_touch_BUTTON2_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON2_PTR2WD_RAM_PARAM_ID               (0xDB02003Cu)

#define key_touch_BUTTON2_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[2].ptr2SnsRam)
#define key_touch_BUTTON2_PTR2SNS_RAM_OFFSET                (64u)
#define key_touch_BUTTON2_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON2_PTR2SNS_RAM_PARAM_ID              (0xDA020040u)

#define key_touch_BUTTON2_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[2].ptr2FltrHistory)
#define key_touch_BUTTON2_PTR2FLTR_HISTORY_OFFSET           (68u)
#define key_touch_BUTTON2_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON2_PTR2FLTR_HISTORY_PARAM_ID         (0xDB020044u)

#define key_touch_BUTTON2_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[2].ptr2DebounceArr)
#define key_touch_BUTTON2_PTR2DEBOUNCE_OFFSET               (72u)
#define key_touch_BUTTON2_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON2_PTR2DEBOUNCE_PARAM_ID             (0xD8020048u)

#define key_touch_BUTTON2_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[2].staticConfig)
#define key_touch_BUTTON2_STATIC_CONFIG_OFFSET              (76u)
#define key_touch_BUTTON2_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON2_STATIC_CONFIG_PARAM_ID            (0x9602004Cu)

#define key_touch_BUTTON2_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[2].totalNumSns)
#define key_touch_BUTTON2_TOTAL_NUM_SNS_OFFSET              (78u)
#define key_touch_BUTTON2_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON2_TOTAL_NUM_SNS_PARAM_ID            (0x9A02004Eu)

#define key_touch_BUTTON2_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[2].wdgtType)
#define key_touch_BUTTON2_TYPE_OFFSET                       (80u)
#define key_touch_BUTTON2_TYPE_SIZE                         (1u)
#define key_touch_BUTTON2_TYPE_PARAM_ID                     (0x58020050u)

#define key_touch_BUTTON2_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[2].numCols)
#define key_touch_BUTTON2_NUM_COLS_OFFSET                   (81u)
#define key_touch_BUTTON2_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON2_NUM_COLS_PARAM_ID                 (0x5E020051u)

#define key_touch_BUTTON3_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[3].ptr2SnsFlash)
#define key_touch_BUTTON3_PTR2SNS_FLASH_OFFSET              (84u)
#define key_touch_BUTTON3_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON3_PTR2SNS_FLASH_PARAM_ID            (0xDD030054u)

#define key_touch_BUTTON3_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[3].ptr2WdgtRam)
#define key_touch_BUTTON3_PTR2WD_RAM_OFFSET                 (88u)
#define key_touch_BUTTON3_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON3_PTR2WD_RAM_PARAM_ID               (0xDE030058u)

#define key_touch_BUTTON3_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[3].ptr2SnsRam)
#define key_touch_BUTTON3_PTR2SNS_RAM_OFFSET                (92u)
#define key_touch_BUTTON3_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON3_PTR2SNS_RAM_PARAM_ID              (0xDF03005Cu)

#define key_touch_BUTTON3_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[3].ptr2FltrHistory)
#define key_touch_BUTTON3_PTR2FLTR_HISTORY_OFFSET           (96u)
#define key_touch_BUTTON3_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON3_PTR2FLTR_HISTORY_PARAM_ID         (0xD3030060u)

#define key_touch_BUTTON3_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[3].ptr2DebounceArr)
#define key_touch_BUTTON3_PTR2DEBOUNCE_OFFSET               (100u)
#define key_touch_BUTTON3_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON3_PTR2DEBOUNCE_PARAM_ID             (0xD2030064u)

#define key_touch_BUTTON3_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[3].staticConfig)
#define key_touch_BUTTON3_STATIC_CONFIG_OFFSET              (104u)
#define key_touch_BUTTON3_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON3_STATIC_CONFIG_PARAM_ID            (0x9E030068u)

#define key_touch_BUTTON3_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[3].totalNumSns)
#define key_touch_BUTTON3_TOTAL_NUM_SNS_OFFSET              (106u)
#define key_touch_BUTTON3_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON3_TOTAL_NUM_SNS_PARAM_ID            (0x9203006Au)

#define key_touch_BUTTON3_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[3].wdgtType)
#define key_touch_BUTTON3_TYPE_OFFSET                       (108u)
#define key_touch_BUTTON3_TYPE_SIZE                         (1u)
#define key_touch_BUTTON3_TYPE_PARAM_ID                     (0x5703006Cu)

#define key_touch_BUTTON3_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[3].numCols)
#define key_touch_BUTTON3_NUM_COLS_OFFSET                   (109u)
#define key_touch_BUTTON3_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON3_NUM_COLS_PARAM_ID                 (0x5103006Du)

#define key_touch_BUTTON4_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[4].ptr2SnsFlash)
#define key_touch_BUTTON4_PTR2SNS_FLASH_OFFSET              (112u)
#define key_touch_BUTTON4_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON4_PTR2SNS_FLASH_PARAM_ID            (0xDF040070u)

#define key_touch_BUTTON4_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[4].ptr2WdgtRam)
#define key_touch_BUTTON4_PTR2WD_RAM_OFFSET                 (116u)
#define key_touch_BUTTON4_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON4_PTR2WD_RAM_PARAM_ID               (0xDE040074u)

#define key_touch_BUTTON4_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[4].ptr2SnsRam)
#define key_touch_BUTTON4_PTR2SNS_RAM_OFFSET                (120u)
#define key_touch_BUTTON4_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON4_PTR2SNS_RAM_PARAM_ID              (0xDD040078u)

#define key_touch_BUTTON4_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[4].ptr2FltrHistory)
#define key_touch_BUTTON4_PTR2FLTR_HISTORY_OFFSET           (124u)
#define key_touch_BUTTON4_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON4_PTR2FLTR_HISTORY_PARAM_ID         (0xDC04007Cu)

#define key_touch_BUTTON4_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[4].ptr2DebounceArr)
#define key_touch_BUTTON4_PTR2DEBOUNCE_OFFSET               (128u)
#define key_touch_BUTTON4_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON4_PTR2DEBOUNCE_PARAM_ID             (0xDE040080u)

#define key_touch_BUTTON4_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[4].staticConfig)
#define key_touch_BUTTON4_STATIC_CONFIG_OFFSET              (132u)
#define key_touch_BUTTON4_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON4_STATIC_CONFIG_PARAM_ID            (0x90040084u)

#define key_touch_BUTTON4_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[4].totalNumSns)
#define key_touch_BUTTON4_TOTAL_NUM_SNS_OFFSET              (134u)
#define key_touch_BUTTON4_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON4_TOTAL_NUM_SNS_PARAM_ID            (0x9C040086u)

#define key_touch_BUTTON4_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[4].wdgtType)
#define key_touch_BUTTON4_TYPE_OFFSET                       (136u)
#define key_touch_BUTTON4_TYPE_SIZE                         (1u)
#define key_touch_BUTTON4_TYPE_PARAM_ID                     (0x5B040088u)

#define key_touch_BUTTON4_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[4].numCols)
#define key_touch_BUTTON4_NUM_COLS_OFFSET                   (137u)
#define key_touch_BUTTON4_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON4_NUM_COLS_PARAM_ID                 (0x5D040089u)

#define key_touch_BUTTON5_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[5].ptr2SnsFlash)
#define key_touch_BUTTON5_PTR2SNS_FLASH_OFFSET              (140u)
#define key_touch_BUTTON5_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON5_PTR2SNS_FLASH_PARAM_ID            (0xDE05008Cu)

#define key_touch_BUTTON5_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[5].ptr2WdgtRam)
#define key_touch_BUTTON5_PTR2WD_RAM_OFFSET                 (144u)
#define key_touch_BUTTON5_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON5_PTR2WD_RAM_PARAM_ID               (0xD8050090u)

#define key_touch_BUTTON5_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[5].ptr2SnsRam)
#define key_touch_BUTTON5_PTR2SNS_RAM_OFFSET                (148u)
#define key_touch_BUTTON5_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON5_PTR2SNS_RAM_PARAM_ID              (0xD9050094u)

#define key_touch_BUTTON5_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[5].ptr2FltrHistory)
#define key_touch_BUTTON5_PTR2FLTR_HISTORY_OFFSET           (152u)
#define key_touch_BUTTON5_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON5_PTR2FLTR_HISTORY_PARAM_ID         (0xDA050098u)

#define key_touch_BUTTON5_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[5].ptr2DebounceArr)
#define key_touch_BUTTON5_PTR2DEBOUNCE_OFFSET               (156u)
#define key_touch_BUTTON5_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON5_PTR2DEBOUNCE_PARAM_ID             (0xDB05009Cu)

#define key_touch_BUTTON5_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[5].staticConfig)
#define key_touch_BUTTON5_STATIC_CONFIG_OFFSET              (160u)
#define key_touch_BUTTON5_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON5_STATIC_CONFIG_PARAM_ID            (0x980500A0u)

#define key_touch_BUTTON5_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[5].totalNumSns)
#define key_touch_BUTTON5_TOTAL_NUM_SNS_OFFSET              (162u)
#define key_touch_BUTTON5_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON5_TOTAL_NUM_SNS_PARAM_ID            (0x940500A2u)

#define key_touch_BUTTON5_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[5].wdgtType)
#define key_touch_BUTTON5_TYPE_OFFSET                       (164u)
#define key_touch_BUTTON5_TYPE_SIZE                         (1u)
#define key_touch_BUTTON5_TYPE_PARAM_ID                     (0x510500A4u)

#define key_touch_BUTTON5_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[5].numCols)
#define key_touch_BUTTON5_NUM_COLS_OFFSET                   (165u)
#define key_touch_BUTTON5_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON5_NUM_COLS_PARAM_ID                 (0x570500A5u)

#define key_touch_BUTTON6_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[6].ptr2SnsFlash)
#define key_touch_BUTTON6_PTR2SNS_FLASH_OFFSET              (168u)
#define key_touch_BUTTON6_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON6_PTR2SNS_FLASH_PARAM_ID            (0xD00600A8u)

#define key_touch_BUTTON6_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[6].ptr2WdgtRam)
#define key_touch_BUTTON6_PTR2WD_RAM_OFFSET                 (172u)
#define key_touch_BUTTON6_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON6_PTR2WD_RAM_PARAM_ID               (0xD10600ACu)

#define key_touch_BUTTON6_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[6].ptr2SnsRam)
#define key_touch_BUTTON6_PTR2SNS_RAM_OFFSET                (176u)
#define key_touch_BUTTON6_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON6_PTR2SNS_RAM_PARAM_ID              (0xD70600B0u)

#define key_touch_BUTTON6_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[6].ptr2FltrHistory)
#define key_touch_BUTTON6_PTR2FLTR_HISTORY_OFFSET           (180u)
#define key_touch_BUTTON6_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON6_PTR2FLTR_HISTORY_PARAM_ID         (0xD60600B4u)

#define key_touch_BUTTON6_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[6].ptr2DebounceArr)
#define key_touch_BUTTON6_PTR2DEBOUNCE_OFFSET               (184u)
#define key_touch_BUTTON6_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON6_PTR2DEBOUNCE_PARAM_ID             (0xD50600B8u)

#define key_touch_BUTTON6_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[6].staticConfig)
#define key_touch_BUTTON6_STATIC_CONFIG_OFFSET              (188u)
#define key_touch_BUTTON6_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON6_STATIC_CONFIG_PARAM_ID            (0x9B0600BCu)

#define key_touch_BUTTON6_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[6].totalNumSns)
#define key_touch_BUTTON6_TOTAL_NUM_SNS_OFFSET              (190u)
#define key_touch_BUTTON6_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON6_TOTAL_NUM_SNS_PARAM_ID            (0x970600BEu)

#define key_touch_BUTTON6_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[6].wdgtType)
#define key_touch_BUTTON6_TYPE_OFFSET                       (192u)
#define key_touch_BUTTON6_TYPE_SIZE                         (1u)
#define key_touch_BUTTON6_TYPE_PARAM_ID                     (0x520600C0u)

#define key_touch_BUTTON6_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[6].numCols)
#define key_touch_BUTTON6_NUM_COLS_OFFSET                   (193u)
#define key_touch_BUTTON6_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON6_NUM_COLS_PARAM_ID                 (0x540600C1u)

#define key_touch_BUTTON7_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[7].ptr2SnsFlash)
#define key_touch_BUTTON7_PTR2SNS_FLASH_OFFSET              (196u)
#define key_touch_BUTTON7_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON7_PTR2SNS_FLASH_PARAM_ID            (0xD70700C4u)

#define key_touch_BUTTON7_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[7].ptr2WdgtRam)
#define key_touch_BUTTON7_PTR2WD_RAM_OFFSET                 (200u)
#define key_touch_BUTTON7_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON7_PTR2WD_RAM_PARAM_ID               (0xD40700C8u)

#define key_touch_BUTTON7_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[7].ptr2SnsRam)
#define key_touch_BUTTON7_PTR2SNS_RAM_OFFSET                (204u)
#define key_touch_BUTTON7_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON7_PTR2SNS_RAM_PARAM_ID              (0xD50700CCu)

#define key_touch_BUTTON7_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[7].ptr2FltrHistory)
#define key_touch_BUTTON7_PTR2FLTR_HISTORY_OFFSET           (208u)
#define key_touch_BUTTON7_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON7_PTR2FLTR_HISTORY_PARAM_ID         (0xD30700D0u)

#define key_touch_BUTTON7_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[7].ptr2DebounceArr)
#define key_touch_BUTTON7_PTR2DEBOUNCE_OFFSET               (212u)
#define key_touch_BUTTON7_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON7_PTR2DEBOUNCE_PARAM_ID             (0xD20700D4u)

#define key_touch_BUTTON7_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[7].staticConfig)
#define key_touch_BUTTON7_STATIC_CONFIG_OFFSET              (216u)
#define key_touch_BUTTON7_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON7_STATIC_CONFIG_PARAM_ID            (0x9E0700D8u)

#define key_touch_BUTTON7_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[7].totalNumSns)
#define key_touch_BUTTON7_TOTAL_NUM_SNS_OFFSET              (218u)
#define key_touch_BUTTON7_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON7_TOTAL_NUM_SNS_PARAM_ID            (0x920700DAu)

#define key_touch_BUTTON7_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[7].wdgtType)
#define key_touch_BUTTON7_TYPE_OFFSET                       (220u)
#define key_touch_BUTTON7_TYPE_SIZE                         (1u)
#define key_touch_BUTTON7_TYPE_PARAM_ID                     (0x570700DCu)

#define key_touch_BUTTON7_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[7].numCols)
#define key_touch_BUTTON7_NUM_COLS_OFFSET                   (221u)
#define key_touch_BUTTON7_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON7_NUM_COLS_PARAM_ID                 (0x510700DDu)

#define key_touch_BUTTON8_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[8].ptr2SnsFlash)
#define key_touch_BUTTON8_PTR2SNS_FLASH_OFFSET              (224u)
#define key_touch_BUTTON8_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON8_PTR2SNS_FLASH_PARAM_ID            (0xD40800E0u)

#define key_touch_BUTTON8_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[8].ptr2WdgtRam)
#define key_touch_BUTTON8_PTR2WD_RAM_OFFSET                 (228u)
#define key_touch_BUTTON8_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON8_PTR2WD_RAM_PARAM_ID               (0xD50800E4u)

#define key_touch_BUTTON8_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[8].ptr2SnsRam)
#define key_touch_BUTTON8_PTR2SNS_RAM_OFFSET                (232u)
#define key_touch_BUTTON8_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON8_PTR2SNS_RAM_PARAM_ID              (0xD60800E8u)

#define key_touch_BUTTON8_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[8].ptr2FltrHistory)
#define key_touch_BUTTON8_PTR2FLTR_HISTORY_OFFSET           (236u)
#define key_touch_BUTTON8_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON8_PTR2FLTR_HISTORY_PARAM_ID         (0xD70800ECu)

#define key_touch_BUTTON8_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[8].ptr2DebounceArr)
#define key_touch_BUTTON8_PTR2DEBOUNCE_OFFSET               (240u)
#define key_touch_BUTTON8_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON8_PTR2DEBOUNCE_PARAM_ID             (0xD10800F0u)

#define key_touch_BUTTON8_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[8].staticConfig)
#define key_touch_BUTTON8_STATIC_CONFIG_OFFSET              (244u)
#define key_touch_BUTTON8_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON8_STATIC_CONFIG_PARAM_ID            (0x9F0800F4u)

#define key_touch_BUTTON8_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[8].totalNumSns)
#define key_touch_BUTTON8_TOTAL_NUM_SNS_OFFSET              (246u)
#define key_touch_BUTTON8_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON8_TOTAL_NUM_SNS_PARAM_ID            (0x930800F6u)

#define key_touch_BUTTON8_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[8].wdgtType)
#define key_touch_BUTTON8_TYPE_OFFSET                       (248u)
#define key_touch_BUTTON8_TYPE_SIZE                         (1u)
#define key_touch_BUTTON8_TYPE_PARAM_ID                     (0x540800F8u)

#define key_touch_BUTTON8_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[8].numCols)
#define key_touch_BUTTON8_NUM_COLS_OFFSET                   (249u)
#define key_touch_BUTTON8_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON8_NUM_COLS_PARAM_ID                 (0x520800F9u)

#define key_touch_BUTTON9_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[9].ptr2SnsFlash)
#define key_touch_BUTTON9_PTR2SNS_FLASH_OFFSET              (252u)
#define key_touch_BUTTON9_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON9_PTR2SNS_FLASH_PARAM_ID            (0xD10900FCu)

#define key_touch_BUTTON9_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[9].ptr2WdgtRam)
#define key_touch_BUTTON9_PTR2WD_RAM_OFFSET                 (256u)
#define key_touch_BUTTON9_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON9_PTR2WD_RAM_PARAM_ID               (0xD8090100u)

#define key_touch_BUTTON9_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[9].ptr2SnsRam)
#define key_touch_BUTTON9_PTR2SNS_RAM_OFFSET                (260u)
#define key_touch_BUTTON9_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON9_PTR2SNS_RAM_PARAM_ID              (0xD9090104u)

#define key_touch_BUTTON9_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[9].ptr2FltrHistory)
#define key_touch_BUTTON9_PTR2FLTR_HISTORY_OFFSET           (264u)
#define key_touch_BUTTON9_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON9_PTR2FLTR_HISTORY_PARAM_ID         (0xDA090108u)

#define key_touch_BUTTON9_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[9].ptr2DebounceArr)
#define key_touch_BUTTON9_PTR2DEBOUNCE_OFFSET               (268u)
#define key_touch_BUTTON9_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON9_PTR2DEBOUNCE_PARAM_ID             (0xDB09010Cu)

#define key_touch_BUTTON9_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[9].staticConfig)
#define key_touch_BUTTON9_STATIC_CONFIG_OFFSET              (272u)
#define key_touch_BUTTON9_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON9_STATIC_CONFIG_PARAM_ID            (0x92090110u)

#define key_touch_BUTTON9_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[9].totalNumSns)
#define key_touch_BUTTON9_TOTAL_NUM_SNS_OFFSET              (274u)
#define key_touch_BUTTON9_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON9_TOTAL_NUM_SNS_PARAM_ID            (0x9E090112u)

#define key_touch_BUTTON9_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[9].wdgtType)
#define key_touch_BUTTON9_TYPE_OFFSET                       (276u)
#define key_touch_BUTTON9_TYPE_SIZE                         (1u)
#define key_touch_BUTTON9_TYPE_PARAM_ID                     (0x5B090114u)

#define key_touch_BUTTON9_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[9].numCols)
#define key_touch_BUTTON9_NUM_COLS_OFFSET                   (277u)
#define key_touch_BUTTON9_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON9_NUM_COLS_PARAM_ID                 (0x5D090115u)

#define key_touch_BUTTON10_PTR2SNS_FLASH_VALUE              (key_touch_dsFlash.wdgtArray[10].ptr2SnsFlash)
#define key_touch_BUTTON10_PTR2SNS_FLASH_OFFSET             (280u)
#define key_touch_BUTTON10_PTR2SNS_FLASH_SIZE               (4u)
#define key_touch_BUTTON10_PTR2SNS_FLASH_PARAM_ID           (0xDA0A0118u)

#define key_touch_BUTTON10_PTR2WD_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[10].ptr2WdgtRam)
#define key_touch_BUTTON10_PTR2WD_RAM_OFFSET                (284u)
#define key_touch_BUTTON10_PTR2WD_RAM_SIZE                  (4u)
#define key_touch_BUTTON10_PTR2WD_RAM_PARAM_ID              (0xDB0A011Cu)

#define key_touch_BUTTON10_PTR2SNS_RAM_VALUE                (key_touch_dsFlash.wdgtArray[10].ptr2SnsRam)
#define key_touch_BUTTON10_PTR2SNS_RAM_OFFSET               (288u)
#define key_touch_BUTTON10_PTR2SNS_RAM_SIZE                 (4u)
#define key_touch_BUTTON10_PTR2SNS_RAM_PARAM_ID             (0xD70A0120u)

#define key_touch_BUTTON10_PTR2FLTR_HISTORY_VALUE           (key_touch_dsFlash.wdgtArray[10].ptr2FltrHistory)
#define key_touch_BUTTON10_PTR2FLTR_HISTORY_OFFSET          (292u)
#define key_touch_BUTTON10_PTR2FLTR_HISTORY_SIZE            (4u)
#define key_touch_BUTTON10_PTR2FLTR_HISTORY_PARAM_ID        (0xD60A0124u)

#define key_touch_BUTTON10_PTR2DEBOUNCE_VALUE               (key_touch_dsFlash.wdgtArray[10].ptr2DebounceArr)
#define key_touch_BUTTON10_PTR2DEBOUNCE_OFFSET              (296u)
#define key_touch_BUTTON10_PTR2DEBOUNCE_SIZE                (4u)
#define key_touch_BUTTON10_PTR2DEBOUNCE_PARAM_ID            (0xD50A0128u)

#define key_touch_BUTTON10_STATIC_CONFIG_VALUE              (key_touch_dsFlash.wdgtArray[10].staticConfig)
#define key_touch_BUTTON10_STATIC_CONFIG_OFFSET             (300u)
#define key_touch_BUTTON10_STATIC_CONFIG_SIZE               (2u)
#define key_touch_BUTTON10_STATIC_CONFIG_PARAM_ID           (0x9B0A012Cu)

#define key_touch_BUTTON10_TOTAL_NUM_SNS_VALUE              (key_touch_dsFlash.wdgtArray[10].totalNumSns)
#define key_touch_BUTTON10_TOTAL_NUM_SNS_OFFSET             (302u)
#define key_touch_BUTTON10_TOTAL_NUM_SNS_SIZE               (2u)
#define key_touch_BUTTON10_TOTAL_NUM_SNS_PARAM_ID           (0x970A012Eu)

#define key_touch_BUTTON10_TYPE_VALUE                       (key_touch_dsFlash.wdgtArray[10].wdgtType)
#define key_touch_BUTTON10_TYPE_OFFSET                      (304u)
#define key_touch_BUTTON10_TYPE_SIZE                        (1u)
#define key_touch_BUTTON10_TYPE_PARAM_ID                    (0x550A0130u)

#define key_touch_BUTTON10_NUM_COLS_VALUE                   (key_touch_dsFlash.wdgtArray[10].numCols)
#define key_touch_BUTTON10_NUM_COLS_OFFSET                  (305u)
#define key_touch_BUTTON10_NUM_COLS_SIZE                    (1u)
#define key_touch_BUTTON10_NUM_COLS_PARAM_ID                (0x530A0131u)

#define key_touch_BUTTON11_PTR2SNS_FLASH_VALUE              (key_touch_dsFlash.wdgtArray[11].ptr2SnsFlash)
#define key_touch_BUTTON11_PTR2SNS_FLASH_OFFSET             (308u)
#define key_touch_BUTTON11_PTR2SNS_FLASH_SIZE               (4u)
#define key_touch_BUTTON11_PTR2SNS_FLASH_PARAM_ID           (0xD00B0134u)

#define key_touch_BUTTON11_PTR2WD_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[11].ptr2WdgtRam)
#define key_touch_BUTTON11_PTR2WD_RAM_OFFSET                (312u)
#define key_touch_BUTTON11_PTR2WD_RAM_SIZE                  (4u)
#define key_touch_BUTTON11_PTR2WD_RAM_PARAM_ID              (0xD30B0138u)

#define key_touch_BUTTON11_PTR2SNS_RAM_VALUE                (key_touch_dsFlash.wdgtArray[11].ptr2SnsRam)
#define key_touch_BUTTON11_PTR2SNS_RAM_OFFSET               (316u)
#define key_touch_BUTTON11_PTR2SNS_RAM_SIZE                 (4u)
#define key_touch_BUTTON11_PTR2SNS_RAM_PARAM_ID             (0xD20B013Cu)

#define key_touch_BUTTON11_PTR2FLTR_HISTORY_VALUE           (key_touch_dsFlash.wdgtArray[11].ptr2FltrHistory)
#define key_touch_BUTTON11_PTR2FLTR_HISTORY_OFFSET          (320u)
#define key_touch_BUTTON11_PTR2FLTR_HISTORY_SIZE            (4u)
#define key_touch_BUTTON11_PTR2FLTR_HISTORY_PARAM_ID        (0xD30B0140u)

#define key_touch_BUTTON11_PTR2DEBOUNCE_VALUE               (key_touch_dsFlash.wdgtArray[11].ptr2DebounceArr)
#define key_touch_BUTTON11_PTR2DEBOUNCE_OFFSET              (324u)
#define key_touch_BUTTON11_PTR2DEBOUNCE_SIZE                (4u)
#define key_touch_BUTTON11_PTR2DEBOUNCE_PARAM_ID            (0xD20B0144u)

#define key_touch_BUTTON11_STATIC_CONFIG_VALUE              (key_touch_dsFlash.wdgtArray[11].staticConfig)
#define key_touch_BUTTON11_STATIC_CONFIG_OFFSET             (328u)
#define key_touch_BUTTON11_STATIC_CONFIG_SIZE               (2u)
#define key_touch_BUTTON11_STATIC_CONFIG_PARAM_ID           (0x9E0B0148u)

#define key_touch_BUTTON11_TOTAL_NUM_SNS_VALUE              (key_touch_dsFlash.wdgtArray[11].totalNumSns)
#define key_touch_BUTTON11_TOTAL_NUM_SNS_OFFSET             (330u)
#define key_touch_BUTTON11_TOTAL_NUM_SNS_SIZE               (2u)
#define key_touch_BUTTON11_TOTAL_NUM_SNS_PARAM_ID           (0x920B014Au)

#define key_touch_BUTTON11_TYPE_VALUE                       (key_touch_dsFlash.wdgtArray[11].wdgtType)
#define key_touch_BUTTON11_TYPE_OFFSET                      (332u)
#define key_touch_BUTTON11_TYPE_SIZE                        (1u)
#define key_touch_BUTTON11_TYPE_PARAM_ID                    (0x570B014Cu)

#define key_touch_BUTTON11_NUM_COLS_VALUE                   (key_touch_dsFlash.wdgtArray[11].numCols)
#define key_touch_BUTTON11_NUM_COLS_OFFSET                  (333u)
#define key_touch_BUTTON11_NUM_COLS_SIZE                    (1u)
#define key_touch_BUTTON11_NUM_COLS_PARAM_ID                (0x510B014Du)


#endif /* End CY_CAPSENSE_key_touch_REGISTER_MAP_H */

/* [] END OF FILE */
