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

#define key_touch_BUTTON0_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button0.resolution)
#define key_touch_BUTTON0_RESOLUTION_OFFSET                 (36u)
#define key_touch_BUTTON0_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON0_RESOLUTION_PARAM_ID               (0x81800024u)

#define key_touch_BUTTON0_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button0.fingerTh)
#define key_touch_BUTTON0_FINGER_TH_OFFSET                  (38u)
#define key_touch_BUTTON0_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON0_FINGER_TH_PARAM_ID                (0x8D800026u)

#define key_touch_BUTTON0_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button0.noiseTh)
#define key_touch_BUTTON0_NOISE_TH_OFFSET                   (40u)
#define key_touch_BUTTON0_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON0_NOISE_TH_PARAM_ID                 (0x4A800028u)

#define key_touch_BUTTON0_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button0.nNoiseTh)
#define key_touch_BUTTON0_NNOISE_TH_OFFSET                  (41u)
#define key_touch_BUTTON0_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON0_NNOISE_TH_PARAM_ID                (0x4C800029u)

#define key_touch_BUTTON0_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button0.hysteresis)
#define key_touch_BUTTON0_HYSTERESIS_OFFSET                 (42u)
#define key_touch_BUTTON0_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON0_HYSTERESIS_PARAM_ID               (0x4680002Au)

#define key_touch_BUTTON0_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button0.onDebounce)
#define key_touch_BUTTON0_ON_DEBOUNCE_OFFSET                (43u)
#define key_touch_BUTTON0_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON0_ON_DEBOUNCE_PARAM_ID              (0x4080002Bu)

#define key_touch_BUTTON0_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button0.lowBslnRst)
#define key_touch_BUTTON0_LOW_BSLN_RST_OFFSET               (44u)
#define key_touch_BUTTON0_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON0_LOW_BSLN_RST_PARAM_ID             (0x4B80002Cu)

#define key_touch_BUTTON0_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button0.bslnCoeff)
#define key_touch_BUTTON0_BSLN_COEFF_OFFSET                 (45u)
#define key_touch_BUTTON0_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON0_BSLN_COEFF_PARAM_ID               (0x6680002Du)

#define key_touch_BUTTON0_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button0.idacMod[0u])
#define key_touch_BUTTON0_IDAC_MOD0_OFFSET                  (46u)
#define key_touch_BUTTON0_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON0_IDAC_MOD0_PARAM_ID                (0x4A00002Eu)

#define key_touch_BUTTON0_SNS_CLK_VALUE                     (key_touch_dsRam.wdgtList.button0.snsClk)
#define key_touch_BUTTON0_SNS_CLK_OFFSET                    (47u)
#define key_touch_BUTTON0_SNS_CLK_SIZE                      (1u)
#define key_touch_BUTTON0_SNS_CLK_PARAM_ID                  (0x4180002Fu)

#define key_touch_BUTTON0_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button0.snsClkSource)
#define key_touch_BUTTON0_SNS_CLK_SOURCE_OFFSET             (48u)
#define key_touch_BUTTON0_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON0_SNS_CLK_SOURCE_PARAM_ID           (0x4D800030u)

#define key_touch_BUTTON0_FINGER_CAP_VALUE                  (key_touch_dsRam.wdgtList.button0.fingerCap)
#define key_touch_BUTTON0_FINGER_CAP_OFFSET                 (50u)
#define key_touch_BUTTON0_FINGER_CAP_SIZE                   (2u)
#define key_touch_BUTTON0_FINGER_CAP_PARAM_ID               (0xAF000032u)

#define key_touch_BUTTON0_SIGPFC_VALUE                      (key_touch_dsRam.wdgtList.button0.sigPFC)
#define key_touch_BUTTON0_SIGPFC_OFFSET                     (52u)
#define key_touch_BUTTON0_SIGPFC_SIZE                       (2u)
#define key_touch_BUTTON0_SIGPFC_PARAM_ID                   (0xA2000034u)

#define key_touch_BUTTON1_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button1.resolution)
#define key_touch_BUTTON1_RESOLUTION_OFFSET                 (54u)
#define key_touch_BUTTON1_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON1_RESOLUTION_PARAM_ID               (0x8B810036u)

#define key_touch_BUTTON1_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button1.fingerTh)
#define key_touch_BUTTON1_FINGER_TH_OFFSET                  (56u)
#define key_touch_BUTTON1_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON1_FINGER_TH_PARAM_ID                (0x84810038u)

#define key_touch_BUTTON1_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button1.noiseTh)
#define key_touch_BUTTON1_NOISE_TH_OFFSET                   (58u)
#define key_touch_BUTTON1_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON1_NOISE_TH_PARAM_ID                 (0x4081003Au)

#define key_touch_BUTTON1_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button1.nNoiseTh)
#define key_touch_BUTTON1_NNOISE_TH_OFFSET                  (59u)
#define key_touch_BUTTON1_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON1_NNOISE_TH_PARAM_ID                (0x4681003Bu)

#define key_touch_BUTTON1_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button1.hysteresis)
#define key_touch_BUTTON1_HYSTERESIS_OFFSET                 (60u)
#define key_touch_BUTTON1_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON1_HYSTERESIS_PARAM_ID               (0x4D81003Cu)

#define key_touch_BUTTON1_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button1.onDebounce)
#define key_touch_BUTTON1_ON_DEBOUNCE_OFFSET                (61u)
#define key_touch_BUTTON1_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON1_ON_DEBOUNCE_PARAM_ID              (0x4B81003Du)

#define key_touch_BUTTON1_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button1.lowBslnRst)
#define key_touch_BUTTON1_LOW_BSLN_RST_OFFSET               (62u)
#define key_touch_BUTTON1_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON1_LOW_BSLN_RST_PARAM_ID             (0x4181003Eu)

#define key_touch_BUTTON1_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button1.bslnCoeff)
#define key_touch_BUTTON1_BSLN_COEFF_OFFSET                 (63u)
#define key_touch_BUTTON1_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON1_BSLN_COEFF_PARAM_ID               (0x6C81003Fu)

#define key_touch_BUTTON1_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button1.idacMod[0u])
#define key_touch_BUTTON1_IDAC_MOD0_OFFSET                  (64u)
#define key_touch_BUTTON1_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON1_IDAC_MOD0_PARAM_ID                (0x41010040u)

#define key_touch_BUTTON1_SNS_CLK_VALUE                     (key_touch_dsRam.wdgtList.button1.snsClk)
#define key_touch_BUTTON1_SNS_CLK_OFFSET                    (65u)
#define key_touch_BUTTON1_SNS_CLK_SIZE                      (1u)
#define key_touch_BUTTON1_SNS_CLK_PARAM_ID                  (0x4A810041u)

#define key_touch_BUTTON1_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button1.snsClkSource)
#define key_touch_BUTTON1_SNS_CLK_SOURCE_OFFSET             (66u)
#define key_touch_BUTTON1_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON1_SNS_CLK_SOURCE_PARAM_ID           (0x40810042u)

#define key_touch_BUTTON1_FINGER_CAP_VALUE                  (key_touch_dsRam.wdgtList.button1.fingerCap)
#define key_touch_BUTTON1_FINGER_CAP_OFFSET                 (68u)
#define key_touch_BUTTON1_FINGER_CAP_SIZE                   (2u)
#define key_touch_BUTTON1_FINGER_CAP_PARAM_ID               (0xA3010044u)

#define key_touch_BUTTON1_SIGPFC_VALUE                      (key_touch_dsRam.wdgtList.button1.sigPFC)
#define key_touch_BUTTON1_SIGPFC_OFFSET                     (70u)
#define key_touch_BUTTON1_SIGPFC_SIZE                       (2u)
#define key_touch_BUTTON1_SIGPFC_PARAM_ID                   (0xAF010046u)

#define key_touch_BUTTON2_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button2.resolution)
#define key_touch_BUTTON2_RESOLUTION_OFFSET                 (72u)
#define key_touch_BUTTON2_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON2_RESOLUTION_PARAM_ID               (0x83820048u)

#define key_touch_BUTTON2_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button2.fingerTh)
#define key_touch_BUTTON2_FINGER_TH_OFFSET                  (74u)
#define key_touch_BUTTON2_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON2_FINGER_TH_PARAM_ID                (0x8F82004Au)

#define key_touch_BUTTON2_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button2.noiseTh)
#define key_touch_BUTTON2_NOISE_TH_OFFSET                   (76u)
#define key_touch_BUTTON2_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON2_NOISE_TH_PARAM_ID                 (0x4A82004Cu)

#define key_touch_BUTTON2_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button2.nNoiseTh)
#define key_touch_BUTTON2_NNOISE_TH_OFFSET                  (77u)
#define key_touch_BUTTON2_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON2_NNOISE_TH_PARAM_ID                (0x4C82004Du)

#define key_touch_BUTTON2_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button2.hysteresis)
#define key_touch_BUTTON2_HYSTERESIS_OFFSET                 (78u)
#define key_touch_BUTTON2_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON2_HYSTERESIS_PARAM_ID               (0x4682004Eu)

#define key_touch_BUTTON2_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button2.onDebounce)
#define key_touch_BUTTON2_ON_DEBOUNCE_OFFSET                (79u)
#define key_touch_BUTTON2_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON2_ON_DEBOUNCE_PARAM_ID              (0x4082004Fu)

#define key_touch_BUTTON2_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button2.lowBslnRst)
#define key_touch_BUTTON2_LOW_BSLN_RST_OFFSET               (80u)
#define key_touch_BUTTON2_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON2_LOW_BSLN_RST_PARAM_ID             (0x4C820050u)

#define key_touch_BUTTON2_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button2.bslnCoeff)
#define key_touch_BUTTON2_BSLN_COEFF_OFFSET                 (81u)
#define key_touch_BUTTON2_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON2_BSLN_COEFF_PARAM_ID               (0x61820051u)

#define key_touch_BUTTON2_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button2.idacMod[0u])
#define key_touch_BUTTON2_IDAC_MOD0_OFFSET                  (82u)
#define key_touch_BUTTON2_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON2_IDAC_MOD0_PARAM_ID                (0x4D020052u)

#define key_touch_BUTTON2_SNS_CLK_VALUE                     (key_touch_dsRam.wdgtList.button2.snsClk)
#define key_touch_BUTTON2_SNS_CLK_OFFSET                    (83u)
#define key_touch_BUTTON2_SNS_CLK_SIZE                      (1u)
#define key_touch_BUTTON2_SNS_CLK_PARAM_ID                  (0x46820053u)

#define key_touch_BUTTON2_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button2.snsClkSource)
#define key_touch_BUTTON2_SNS_CLK_SOURCE_OFFSET             (84u)
#define key_touch_BUTTON2_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON2_SNS_CLK_SOURCE_PARAM_ID           (0x4D820054u)

#define key_touch_BUTTON2_FINGER_CAP_VALUE                  (key_touch_dsRam.wdgtList.button2.fingerCap)
#define key_touch_BUTTON2_FINGER_CAP_OFFSET                 (86u)
#define key_touch_BUTTON2_FINGER_CAP_SIZE                   (2u)
#define key_touch_BUTTON2_FINGER_CAP_PARAM_ID               (0xAF020056u)

#define key_touch_BUTTON2_SIGPFC_VALUE                      (key_touch_dsRam.wdgtList.button2.sigPFC)
#define key_touch_BUTTON2_SIGPFC_OFFSET                     (88u)
#define key_touch_BUTTON2_SIGPFC_SIZE                       (2u)
#define key_touch_BUTTON2_SIGPFC_PARAM_ID                   (0xA0020058u)

#define key_touch_BUTTON3_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button3.resolution)
#define key_touch_BUTTON3_RESOLUTION_OFFSET                 (90u)
#define key_touch_BUTTON3_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON3_RESOLUTION_PARAM_ID               (0x8983005Au)

#define key_touch_BUTTON3_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button3.fingerTh)
#define key_touch_BUTTON3_FINGER_TH_OFFSET                  (92u)
#define key_touch_BUTTON3_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON3_FINGER_TH_PARAM_ID                (0x8483005Cu)

#define key_touch_BUTTON3_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button3.noiseTh)
#define key_touch_BUTTON3_NOISE_TH_OFFSET                   (94u)
#define key_touch_BUTTON3_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON3_NOISE_TH_PARAM_ID                 (0x4083005Eu)

#define key_touch_BUTTON3_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button3.nNoiseTh)
#define key_touch_BUTTON3_NNOISE_TH_OFFSET                  (95u)
#define key_touch_BUTTON3_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON3_NNOISE_TH_PARAM_ID                (0x4683005Fu)

#define key_touch_BUTTON3_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button3.hysteresis)
#define key_touch_BUTTON3_HYSTERESIS_OFFSET                 (96u)
#define key_touch_BUTTON3_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON3_HYSTERESIS_PARAM_ID               (0x40830060u)

#define key_touch_BUTTON3_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button3.onDebounce)
#define key_touch_BUTTON3_ON_DEBOUNCE_OFFSET                (97u)
#define key_touch_BUTTON3_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON3_ON_DEBOUNCE_PARAM_ID              (0x46830061u)

#define key_touch_BUTTON3_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button3.lowBslnRst)
#define key_touch_BUTTON3_LOW_BSLN_RST_OFFSET               (98u)
#define key_touch_BUTTON3_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON3_LOW_BSLN_RST_PARAM_ID             (0x4C830062u)

#define key_touch_BUTTON3_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button3.bslnCoeff)
#define key_touch_BUTTON3_BSLN_COEFF_OFFSET                 (99u)
#define key_touch_BUTTON3_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON3_BSLN_COEFF_PARAM_ID               (0x61830063u)

#define key_touch_BUTTON3_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button3.idacMod[0u])
#define key_touch_BUTTON3_IDAC_MOD0_OFFSET                  (100u)
#define key_touch_BUTTON3_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON3_IDAC_MOD0_PARAM_ID                (0x4C030064u)

#define key_touch_BUTTON3_SNS_CLK_VALUE                     (key_touch_dsRam.wdgtList.button3.snsClk)
#define key_touch_BUTTON3_SNS_CLK_OFFSET                    (101u)
#define key_touch_BUTTON3_SNS_CLK_SIZE                      (1u)
#define key_touch_BUTTON3_SNS_CLK_PARAM_ID                  (0x47830065u)

#define key_touch_BUTTON3_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button3.snsClkSource)
#define key_touch_BUTTON3_SNS_CLK_SOURCE_OFFSET             (102u)
#define key_touch_BUTTON3_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON3_SNS_CLK_SOURCE_PARAM_ID           (0x4D830066u)

#define key_touch_BUTTON3_FINGER_CAP_VALUE                  (key_touch_dsRam.wdgtList.button3.fingerCap)
#define key_touch_BUTTON3_FINGER_CAP_OFFSET                 (104u)
#define key_touch_BUTTON3_FINGER_CAP_SIZE                   (2u)
#define key_touch_BUTTON3_FINGER_CAP_PARAM_ID               (0xAC030068u)

#define key_touch_BUTTON3_SIGPFC_VALUE                      (key_touch_dsRam.wdgtList.button3.sigPFC)
#define key_touch_BUTTON3_SIGPFC_OFFSET                     (106u)
#define key_touch_BUTTON3_SIGPFC_SIZE                       (2u)
#define key_touch_BUTTON3_SIGPFC_PARAM_ID                   (0xA003006Au)

#define key_touch_BUTTON4_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button4.resolution)
#define key_touch_BUTTON4_RESOLUTION_OFFSET                 (108u)
#define key_touch_BUTTON4_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON4_RESOLUTION_PARAM_ID               (0x8284006Cu)

#define key_touch_BUTTON4_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button4.fingerTh)
#define key_touch_BUTTON4_FINGER_TH_OFFSET                  (110u)
#define key_touch_BUTTON4_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON4_FINGER_TH_PARAM_ID                (0x8E84006Eu)

#define key_touch_BUTTON4_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button4.noiseTh)
#define key_touch_BUTTON4_NOISE_TH_OFFSET                   (112u)
#define key_touch_BUTTON4_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON4_NOISE_TH_PARAM_ID                 (0x4C840070u)

#define key_touch_BUTTON4_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button4.nNoiseTh)
#define key_touch_BUTTON4_NNOISE_TH_OFFSET                  (113u)
#define key_touch_BUTTON4_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON4_NNOISE_TH_PARAM_ID                (0x4A840071u)

#define key_touch_BUTTON4_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button4.hysteresis)
#define key_touch_BUTTON4_HYSTERESIS_OFFSET                 (114u)
#define key_touch_BUTTON4_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON4_HYSTERESIS_PARAM_ID               (0x40840072u)

#define key_touch_BUTTON4_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button4.onDebounce)
#define key_touch_BUTTON4_ON_DEBOUNCE_OFFSET                (115u)
#define key_touch_BUTTON4_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON4_ON_DEBOUNCE_PARAM_ID              (0x46840073u)

#define key_touch_BUTTON4_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button4.lowBslnRst)
#define key_touch_BUTTON4_LOW_BSLN_RST_OFFSET               (116u)
#define key_touch_BUTTON4_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON4_LOW_BSLN_RST_PARAM_ID             (0x4D840074u)

#define key_touch_BUTTON4_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button4.bslnCoeff)
#define key_touch_BUTTON4_BSLN_COEFF_OFFSET                 (117u)
#define key_touch_BUTTON4_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON4_BSLN_COEFF_PARAM_ID               (0x60840075u)

#define key_touch_BUTTON4_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button4.idacMod[0u])
#define key_touch_BUTTON4_IDAC_MOD0_OFFSET                  (118u)
#define key_touch_BUTTON4_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON4_IDAC_MOD0_PARAM_ID                (0x4C040076u)

#define key_touch_BUTTON4_SNS_CLK_VALUE                     (key_touch_dsRam.wdgtList.button4.snsClk)
#define key_touch_BUTTON4_SNS_CLK_OFFSET                    (119u)
#define key_touch_BUTTON4_SNS_CLK_SIZE                      (1u)
#define key_touch_BUTTON4_SNS_CLK_PARAM_ID                  (0x47840077u)

#define key_touch_BUTTON4_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button4.snsClkSource)
#define key_touch_BUTTON4_SNS_CLK_SOURCE_OFFSET             (120u)
#define key_touch_BUTTON4_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON4_SNS_CLK_SOURCE_PARAM_ID           (0x4E840078u)

#define key_touch_BUTTON4_FINGER_CAP_VALUE                  (key_touch_dsRam.wdgtList.button4.fingerCap)
#define key_touch_BUTTON4_FINGER_CAP_OFFSET                 (122u)
#define key_touch_BUTTON4_FINGER_CAP_SIZE                   (2u)
#define key_touch_BUTTON4_FINGER_CAP_PARAM_ID               (0xAC04007Au)

#define key_touch_BUTTON4_SIGPFC_VALUE                      (key_touch_dsRam.wdgtList.button4.sigPFC)
#define key_touch_BUTTON4_SIGPFC_OFFSET                     (124u)
#define key_touch_BUTTON4_SIGPFC_SIZE                       (2u)
#define key_touch_BUTTON4_SIGPFC_PARAM_ID                   (0xA104007Cu)

#define key_touch_BUTTON5_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button5.resolution)
#define key_touch_BUTTON5_RESOLUTION_OFFSET                 (126u)
#define key_touch_BUTTON5_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON5_RESOLUTION_PARAM_ID               (0x8885007Eu)

#define key_touch_BUTTON5_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button5.fingerTh)
#define key_touch_BUTTON5_FINGER_TH_OFFSET                  (128u)
#define key_touch_BUTTON5_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON5_FINGER_TH_PARAM_ID                (0x86850080u)

#define key_touch_BUTTON5_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button5.noiseTh)
#define key_touch_BUTTON5_NOISE_TH_OFFSET                   (130u)
#define key_touch_BUTTON5_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON5_NOISE_TH_PARAM_ID                 (0x42850082u)

#define key_touch_BUTTON5_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button5.nNoiseTh)
#define key_touch_BUTTON5_NNOISE_TH_OFFSET                  (131u)
#define key_touch_BUTTON5_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON5_NNOISE_TH_PARAM_ID                (0x44850083u)

#define key_touch_BUTTON5_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button5.hysteresis)
#define key_touch_BUTTON5_HYSTERESIS_OFFSET                 (132u)
#define key_touch_BUTTON5_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON5_HYSTERESIS_PARAM_ID               (0x4F850084u)

#define key_touch_BUTTON5_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button5.onDebounce)
#define key_touch_BUTTON5_ON_DEBOUNCE_OFFSET                (133u)
#define key_touch_BUTTON5_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON5_ON_DEBOUNCE_PARAM_ID              (0x49850085u)

#define key_touch_BUTTON5_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button5.lowBslnRst)
#define key_touch_BUTTON5_LOW_BSLN_RST_OFFSET               (134u)
#define key_touch_BUTTON5_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON5_LOW_BSLN_RST_PARAM_ID             (0x43850086u)

#define key_touch_BUTTON5_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button5.bslnCoeff)
#define key_touch_BUTTON5_BSLN_COEFF_OFFSET                 (135u)
#define key_touch_BUTTON5_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON5_BSLN_COEFF_PARAM_ID               (0x6E850087u)

#define key_touch_BUTTON5_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button5.idacMod[0u])
#define key_touch_BUTTON5_IDAC_MOD0_OFFSET                  (136u)
#define key_touch_BUTTON5_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON5_IDAC_MOD0_PARAM_ID                (0x41050088u)

#define key_touch_BUTTON5_SNS_CLK_VALUE                     (key_touch_dsRam.wdgtList.button5.snsClk)
#define key_touch_BUTTON5_SNS_CLK_OFFSET                    (137u)
#define key_touch_BUTTON5_SNS_CLK_SIZE                      (1u)
#define key_touch_BUTTON5_SNS_CLK_PARAM_ID                  (0x4A850089u)

#define key_touch_BUTTON5_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button5.snsClkSource)
#define key_touch_BUTTON5_SNS_CLK_SOURCE_OFFSET             (138u)
#define key_touch_BUTTON5_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON5_SNS_CLK_SOURCE_PARAM_ID           (0x4085008Au)

#define key_touch_BUTTON5_FINGER_CAP_VALUE                  (key_touch_dsRam.wdgtList.button5.fingerCap)
#define key_touch_BUTTON5_FINGER_CAP_OFFSET                 (140u)
#define key_touch_BUTTON5_FINGER_CAP_SIZE                   (2u)
#define key_touch_BUTTON5_FINGER_CAP_PARAM_ID               (0xA305008Cu)

#define key_touch_BUTTON5_SIGPFC_VALUE                      (key_touch_dsRam.wdgtList.button5.sigPFC)
#define key_touch_BUTTON5_SIGPFC_OFFSET                     (142u)
#define key_touch_BUTTON5_SIGPFC_SIZE                       (2u)
#define key_touch_BUTTON5_SIGPFC_PARAM_ID                   (0xAF05008Eu)

#define key_touch_BUTTON6_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button6.resolution)
#define key_touch_BUTTON6_RESOLUTION_OFFSET                 (144u)
#define key_touch_BUTTON6_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON6_RESOLUTION_PARAM_ID               (0x86860090u)

#define key_touch_BUTTON6_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button6.fingerTh)
#define key_touch_BUTTON6_FINGER_TH_OFFSET                  (146u)
#define key_touch_BUTTON6_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON6_FINGER_TH_PARAM_ID                (0x8A860092u)

#define key_touch_BUTTON6_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button6.noiseTh)
#define key_touch_BUTTON6_NOISE_TH_OFFSET                   (148u)
#define key_touch_BUTTON6_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON6_NOISE_TH_PARAM_ID                 (0x4F860094u)

#define key_touch_BUTTON6_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button6.nNoiseTh)
#define key_touch_BUTTON6_NNOISE_TH_OFFSET                  (149u)
#define key_touch_BUTTON6_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON6_NNOISE_TH_PARAM_ID                (0x49860095u)

#define key_touch_BUTTON6_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button6.hysteresis)
#define key_touch_BUTTON6_HYSTERESIS_OFFSET                 (150u)
#define key_touch_BUTTON6_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON6_HYSTERESIS_PARAM_ID               (0x43860096u)

#define key_touch_BUTTON6_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button6.onDebounce)
#define key_touch_BUTTON6_ON_DEBOUNCE_OFFSET                (151u)
#define key_touch_BUTTON6_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON6_ON_DEBOUNCE_PARAM_ID              (0x45860097u)

#define key_touch_BUTTON6_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button6.lowBslnRst)
#define key_touch_BUTTON6_LOW_BSLN_RST_OFFSET               (152u)
#define key_touch_BUTTON6_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON6_LOW_BSLN_RST_PARAM_ID             (0x4C860098u)

#define key_touch_BUTTON6_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button6.bslnCoeff)
#define key_touch_BUTTON6_BSLN_COEFF_OFFSET                 (153u)
#define key_touch_BUTTON6_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON6_BSLN_COEFF_PARAM_ID               (0x61860099u)

#define key_touch_BUTTON6_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button6.idacMod[0u])
#define key_touch_BUTTON6_IDAC_MOD0_OFFSET                  (154u)
#define key_touch_BUTTON6_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON6_IDAC_MOD0_PARAM_ID                (0x4D06009Au)

#define key_touch_BUTTON6_SNS_CLK_VALUE                     (key_touch_dsRam.wdgtList.button6.snsClk)
#define key_touch_BUTTON6_SNS_CLK_OFFSET                    (155u)
#define key_touch_BUTTON6_SNS_CLK_SIZE                      (1u)
#define key_touch_BUTTON6_SNS_CLK_PARAM_ID                  (0x4686009Bu)

#define key_touch_BUTTON6_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button6.snsClkSource)
#define key_touch_BUTTON6_SNS_CLK_SOURCE_OFFSET             (156u)
#define key_touch_BUTTON6_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON6_SNS_CLK_SOURCE_PARAM_ID           (0x4D86009Cu)

#define key_touch_BUTTON6_FINGER_CAP_VALUE                  (key_touch_dsRam.wdgtList.button6.fingerCap)
#define key_touch_BUTTON6_FINGER_CAP_OFFSET                 (158u)
#define key_touch_BUTTON6_FINGER_CAP_SIZE                   (2u)
#define key_touch_BUTTON6_FINGER_CAP_PARAM_ID               (0xAF06009Eu)

#define key_touch_BUTTON6_SIGPFC_VALUE                      (key_touch_dsRam.wdgtList.button6.sigPFC)
#define key_touch_BUTTON6_SIGPFC_OFFSET                     (160u)
#define key_touch_BUTTON6_SIGPFC_SIZE                       (2u)
#define key_touch_BUTTON6_SIGPFC_PARAM_ID                   (0xAF0600A0u)

#define key_touch_BUTTON7_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button7.resolution)
#define key_touch_BUTTON7_RESOLUTION_OFFSET                 (162u)
#define key_touch_BUTTON7_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON7_RESOLUTION_PARAM_ID               (0x868700A2u)

#define key_touch_BUTTON7_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button7.fingerTh)
#define key_touch_BUTTON7_FINGER_TH_OFFSET                  (164u)
#define key_touch_BUTTON7_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON7_FINGER_TH_PARAM_ID                (0x8B8700A4u)

#define key_touch_BUTTON7_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button7.noiseTh)
#define key_touch_BUTTON7_NOISE_TH_OFFSET                   (166u)
#define key_touch_BUTTON7_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON7_NOISE_TH_PARAM_ID                 (0x4F8700A6u)

#define key_touch_BUTTON7_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button7.nNoiseTh)
#define key_touch_BUTTON7_NNOISE_TH_OFFSET                  (167u)
#define key_touch_BUTTON7_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON7_NNOISE_TH_PARAM_ID                (0x498700A7u)

#define key_touch_BUTTON7_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button7.hysteresis)
#define key_touch_BUTTON7_HYSTERESIS_OFFSET                 (168u)
#define key_touch_BUTTON7_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON7_HYSTERESIS_PARAM_ID               (0x408700A8u)

#define key_touch_BUTTON7_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button7.onDebounce)
#define key_touch_BUTTON7_ON_DEBOUNCE_OFFSET                (169u)
#define key_touch_BUTTON7_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON7_ON_DEBOUNCE_PARAM_ID              (0x468700A9u)

#define key_touch_BUTTON7_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button7.lowBslnRst)
#define key_touch_BUTTON7_LOW_BSLN_RST_OFFSET               (170u)
#define key_touch_BUTTON7_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON7_LOW_BSLN_RST_PARAM_ID             (0x4C8700AAu)

#define key_touch_BUTTON7_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button7.bslnCoeff)
#define key_touch_BUTTON7_BSLN_COEFF_OFFSET                 (171u)
#define key_touch_BUTTON7_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON7_BSLN_COEFF_PARAM_ID               (0x618700ABu)

#define key_touch_BUTTON7_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button7.idacMod[0u])
#define key_touch_BUTTON7_IDAC_MOD0_OFFSET                  (172u)
#define key_touch_BUTTON7_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON7_IDAC_MOD0_PARAM_ID                (0x4C0700ACu)

#define key_touch_BUTTON7_SNS_CLK_VALUE                     (key_touch_dsRam.wdgtList.button7.snsClk)
#define key_touch_BUTTON7_SNS_CLK_OFFSET                    (173u)
#define key_touch_BUTTON7_SNS_CLK_SIZE                      (1u)
#define key_touch_BUTTON7_SNS_CLK_PARAM_ID                  (0x478700ADu)

#define key_touch_BUTTON7_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button7.snsClkSource)
#define key_touch_BUTTON7_SNS_CLK_SOURCE_OFFSET             (174u)
#define key_touch_BUTTON7_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON7_SNS_CLK_SOURCE_PARAM_ID           (0x4D8700AEu)

#define key_touch_BUTTON7_FINGER_CAP_VALUE                  (key_touch_dsRam.wdgtList.button7.fingerCap)
#define key_touch_BUTTON7_FINGER_CAP_OFFSET                 (176u)
#define key_touch_BUTTON7_FINGER_CAP_SIZE                   (2u)
#define key_touch_BUTTON7_FINGER_CAP_PARAM_ID               (0xA90700B0u)

#define key_touch_BUTTON7_SIGPFC_VALUE                      (key_touch_dsRam.wdgtList.button7.sigPFC)
#define key_touch_BUTTON7_SIGPFC_OFFSET                     (178u)
#define key_touch_BUTTON7_SIGPFC_SIZE                       (2u)
#define key_touch_BUTTON7_SIGPFC_PARAM_ID                   (0xA50700B2u)

#define key_touch_BUTTON8_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button8.resolution)
#define key_touch_BUTTON8_RESOLUTION_OFFSET                 (180u)
#define key_touch_BUTTON8_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON8_RESOLUTION_PARAM_ID               (0x868800B4u)

#define key_touch_BUTTON8_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button8.fingerTh)
#define key_touch_BUTTON8_FINGER_TH_OFFSET                  (182u)
#define key_touch_BUTTON8_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON8_FINGER_TH_PARAM_ID                (0x8A8800B6u)

#define key_touch_BUTTON8_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button8.noiseTh)
#define key_touch_BUTTON8_NOISE_TH_OFFSET                   (184u)
#define key_touch_BUTTON8_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON8_NOISE_TH_PARAM_ID                 (0x4D8800B8u)

#define key_touch_BUTTON8_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button8.nNoiseTh)
#define key_touch_BUTTON8_NNOISE_TH_OFFSET                  (185u)
#define key_touch_BUTTON8_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON8_NNOISE_TH_PARAM_ID                (0x4B8800B9u)

#define key_touch_BUTTON8_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button8.hysteresis)
#define key_touch_BUTTON8_HYSTERESIS_OFFSET                 (186u)
#define key_touch_BUTTON8_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON8_HYSTERESIS_PARAM_ID               (0x418800BAu)

#define key_touch_BUTTON8_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button8.onDebounce)
#define key_touch_BUTTON8_ON_DEBOUNCE_OFFSET                (187u)
#define key_touch_BUTTON8_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON8_ON_DEBOUNCE_PARAM_ID              (0x478800BBu)

#define key_touch_BUTTON8_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button8.lowBslnRst)
#define key_touch_BUTTON8_LOW_BSLN_RST_OFFSET               (188u)
#define key_touch_BUTTON8_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON8_LOW_BSLN_RST_PARAM_ID             (0x4C8800BCu)

#define key_touch_BUTTON8_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button8.bslnCoeff)
#define key_touch_BUTTON8_BSLN_COEFF_OFFSET                 (189u)
#define key_touch_BUTTON8_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON8_BSLN_COEFF_PARAM_ID               (0x618800BDu)

#define key_touch_BUTTON8_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button8.idacMod[0u])
#define key_touch_BUTTON8_IDAC_MOD0_OFFSET                  (190u)
#define key_touch_BUTTON8_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON8_IDAC_MOD0_PARAM_ID                (0x4D0800BEu)

#define key_touch_BUTTON8_SNS_CLK_VALUE                     (key_touch_dsRam.wdgtList.button8.snsClk)
#define key_touch_BUTTON8_SNS_CLK_OFFSET                    (191u)
#define key_touch_BUTTON8_SNS_CLK_SIZE                      (1u)
#define key_touch_BUTTON8_SNS_CLK_PARAM_ID                  (0x468800BFu)

#define key_touch_BUTTON8_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button8.snsClkSource)
#define key_touch_BUTTON8_SNS_CLK_SOURCE_OFFSET             (192u)
#define key_touch_BUTTON8_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON8_SNS_CLK_SOURCE_PARAM_ID           (0x4D8800C0u)

#define key_touch_BUTTON8_FINGER_CAP_VALUE                  (key_touch_dsRam.wdgtList.button8.fingerCap)
#define key_touch_BUTTON8_FINGER_CAP_OFFSET                 (194u)
#define key_touch_BUTTON8_FINGER_CAP_SIZE                   (2u)
#define key_touch_BUTTON8_FINGER_CAP_PARAM_ID               (0xAF0800C2u)

#define key_touch_BUTTON8_SIGPFC_VALUE                      (key_touch_dsRam.wdgtList.button8.sigPFC)
#define key_touch_BUTTON8_SIGPFC_OFFSET                     (196u)
#define key_touch_BUTTON8_SIGPFC_SIZE                       (2u)
#define key_touch_BUTTON8_SIGPFC_PARAM_ID                   (0xA20800C4u)

#define key_touch_BUTTON9_RESOLUTION_VALUE                  (key_touch_dsRam.wdgtList.button9.resolution)
#define key_touch_BUTTON9_RESOLUTION_OFFSET                 (198u)
#define key_touch_BUTTON9_RESOLUTION_SIZE                   (2u)
#define key_touch_BUTTON9_RESOLUTION_PARAM_ID               (0x8B8900C6u)

#define key_touch_BUTTON9_FINGER_TH_VALUE                   (key_touch_dsRam.wdgtList.button9.fingerTh)
#define key_touch_BUTTON9_FINGER_TH_OFFSET                  (200u)
#define key_touch_BUTTON9_FINGER_TH_SIZE                    (2u)
#define key_touch_BUTTON9_FINGER_TH_PARAM_ID                (0x848900C8u)

#define key_touch_BUTTON9_NOISE_TH_VALUE                    (key_touch_dsRam.wdgtList.button9.noiseTh)
#define key_touch_BUTTON9_NOISE_TH_OFFSET                   (202u)
#define key_touch_BUTTON9_NOISE_TH_SIZE                     (1u)
#define key_touch_BUTTON9_NOISE_TH_PARAM_ID                 (0x408900CAu)

#define key_touch_BUTTON9_NNOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button9.nNoiseTh)
#define key_touch_BUTTON9_NNOISE_TH_OFFSET                  (203u)
#define key_touch_BUTTON9_NNOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON9_NNOISE_TH_PARAM_ID                (0x468900CBu)

#define key_touch_BUTTON9_HYSTERESIS_VALUE                  (key_touch_dsRam.wdgtList.button9.hysteresis)
#define key_touch_BUTTON9_HYSTERESIS_OFFSET                 (204u)
#define key_touch_BUTTON9_HYSTERESIS_SIZE                   (1u)
#define key_touch_BUTTON9_HYSTERESIS_PARAM_ID               (0x4D8900CCu)

#define key_touch_BUTTON9_ON_DEBOUNCE_VALUE                 (key_touch_dsRam.wdgtList.button9.onDebounce)
#define key_touch_BUTTON9_ON_DEBOUNCE_OFFSET                (205u)
#define key_touch_BUTTON9_ON_DEBOUNCE_SIZE                  (1u)
#define key_touch_BUTTON9_ON_DEBOUNCE_PARAM_ID              (0x4B8900CDu)

#define key_touch_BUTTON9_LOW_BSLN_RST_VALUE                (key_touch_dsRam.wdgtList.button9.lowBslnRst)
#define key_touch_BUTTON9_LOW_BSLN_RST_OFFSET               (206u)
#define key_touch_BUTTON9_LOW_BSLN_RST_SIZE                 (1u)
#define key_touch_BUTTON9_LOW_BSLN_RST_PARAM_ID             (0x418900CEu)

#define key_touch_BUTTON9_BSLN_COEFF_VALUE                  (key_touch_dsRam.wdgtList.button9.bslnCoeff)
#define key_touch_BUTTON9_BSLN_COEFF_OFFSET                 (207u)
#define key_touch_BUTTON9_BSLN_COEFF_SIZE                   (1u)
#define key_touch_BUTTON9_BSLN_COEFF_PARAM_ID               (0x6C8900CFu)

#define key_touch_BUTTON9_IDAC_MOD0_VALUE                   (key_touch_dsRam.wdgtList.button9.idacMod[0u])
#define key_touch_BUTTON9_IDAC_MOD0_OFFSET                  (208u)
#define key_touch_BUTTON9_IDAC_MOD0_SIZE                    (1u)
#define key_touch_BUTTON9_IDAC_MOD0_PARAM_ID                (0x460900D0u)

#define key_touch_BUTTON9_SNS_CLK_VALUE                     (key_touch_dsRam.wdgtList.button9.snsClk)
#define key_touch_BUTTON9_SNS_CLK_OFFSET                    (209u)
#define key_touch_BUTTON9_SNS_CLK_SIZE                      (1u)
#define key_touch_BUTTON9_SNS_CLK_PARAM_ID                  (0x4D8900D1u)

#define key_touch_BUTTON9_SNS_CLK_SOURCE_VALUE              (key_touch_dsRam.wdgtList.button9.snsClkSource)
#define key_touch_BUTTON9_SNS_CLK_SOURCE_OFFSET             (210u)
#define key_touch_BUTTON9_SNS_CLK_SOURCE_SIZE               (1u)
#define key_touch_BUTTON9_SNS_CLK_SOURCE_PARAM_ID           (0x478900D2u)

#define key_touch_BUTTON9_FINGER_CAP_VALUE                  (key_touch_dsRam.wdgtList.button9.fingerCap)
#define key_touch_BUTTON9_FINGER_CAP_OFFSET                 (212u)
#define key_touch_BUTTON9_FINGER_CAP_SIZE                   (2u)
#define key_touch_BUTTON9_FINGER_CAP_PARAM_ID               (0xA40900D4u)

#define key_touch_BUTTON9_SIGPFC_VALUE                      (key_touch_dsRam.wdgtList.button9.sigPFC)
#define key_touch_BUTTON9_SIGPFC_OFFSET                     (214u)
#define key_touch_BUTTON9_SIGPFC_SIZE                       (2u)
#define key_touch_BUTTON9_SIGPFC_PARAM_ID                   (0xA80900D6u)

#define key_touch_BUTTON10_RESOLUTION_VALUE                 (key_touch_dsRam.wdgtList.button10.resolution)
#define key_touch_BUTTON10_RESOLUTION_OFFSET                (216u)
#define key_touch_BUTTON10_RESOLUTION_SIZE                  (2u)
#define key_touch_BUTTON10_RESOLUTION_PARAM_ID              (0x848A00D8u)

#define key_touch_BUTTON10_FINGER_TH_VALUE                  (key_touch_dsRam.wdgtList.button10.fingerTh)
#define key_touch_BUTTON10_FINGER_TH_OFFSET                 (218u)
#define key_touch_BUTTON10_FINGER_TH_SIZE                   (2u)
#define key_touch_BUTTON10_FINGER_TH_PARAM_ID               (0x888A00DAu)

#define key_touch_BUTTON10_NOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button10.noiseTh)
#define key_touch_BUTTON10_NOISE_TH_OFFSET                  (220u)
#define key_touch_BUTTON10_NOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON10_NOISE_TH_PARAM_ID                (0x4D8A00DCu)

#define key_touch_BUTTON10_NNOISE_TH_VALUE                  (key_touch_dsRam.wdgtList.button10.nNoiseTh)
#define key_touch_BUTTON10_NNOISE_TH_OFFSET                 (221u)
#define key_touch_BUTTON10_NNOISE_TH_SIZE                   (1u)
#define key_touch_BUTTON10_NNOISE_TH_PARAM_ID               (0x4B8A00DDu)

#define key_touch_BUTTON10_HYSTERESIS_VALUE                 (key_touch_dsRam.wdgtList.button10.hysteresis)
#define key_touch_BUTTON10_HYSTERESIS_OFFSET                (222u)
#define key_touch_BUTTON10_HYSTERESIS_SIZE                  (1u)
#define key_touch_BUTTON10_HYSTERESIS_PARAM_ID              (0x418A00DEu)

#define key_touch_BUTTON10_ON_DEBOUNCE_VALUE                (key_touch_dsRam.wdgtList.button10.onDebounce)
#define key_touch_BUTTON10_ON_DEBOUNCE_OFFSET               (223u)
#define key_touch_BUTTON10_ON_DEBOUNCE_SIZE                 (1u)
#define key_touch_BUTTON10_ON_DEBOUNCE_PARAM_ID             (0x478A00DFu)

#define key_touch_BUTTON10_LOW_BSLN_RST_VALUE               (key_touch_dsRam.wdgtList.button10.lowBslnRst)
#define key_touch_BUTTON10_LOW_BSLN_RST_OFFSET              (224u)
#define key_touch_BUTTON10_LOW_BSLN_RST_SIZE                (1u)
#define key_touch_BUTTON10_LOW_BSLN_RST_PARAM_ID            (0x418A00E0u)

#define key_touch_BUTTON10_BSLN_COEFF_VALUE                 (key_touch_dsRam.wdgtList.button10.bslnCoeff)
#define key_touch_BUTTON10_BSLN_COEFF_OFFSET                (225u)
#define key_touch_BUTTON10_BSLN_COEFF_SIZE                  (1u)
#define key_touch_BUTTON10_BSLN_COEFF_PARAM_ID              (0x6C8A00E1u)

#define key_touch_BUTTON10_IDAC_MOD0_VALUE                  (key_touch_dsRam.wdgtList.button10.idacMod[0u])
#define key_touch_BUTTON10_IDAC_MOD0_OFFSET                 (226u)
#define key_touch_BUTTON10_IDAC_MOD0_SIZE                   (1u)
#define key_touch_BUTTON10_IDAC_MOD0_PARAM_ID               (0x400A00E2u)

#define key_touch_BUTTON10_SNS_CLK_VALUE                    (key_touch_dsRam.wdgtList.button10.snsClk)
#define key_touch_BUTTON10_SNS_CLK_OFFSET                   (227u)
#define key_touch_BUTTON10_SNS_CLK_SIZE                     (1u)
#define key_touch_BUTTON10_SNS_CLK_PARAM_ID                 (0x4B8A00E3u)

#define key_touch_BUTTON10_SNS_CLK_SOURCE_VALUE             (key_touch_dsRam.wdgtList.button10.snsClkSource)
#define key_touch_BUTTON10_SNS_CLK_SOURCE_OFFSET            (228u)
#define key_touch_BUTTON10_SNS_CLK_SOURCE_SIZE              (1u)
#define key_touch_BUTTON10_SNS_CLK_SOURCE_PARAM_ID          (0x408A00E4u)

#define key_touch_BUTTON10_FINGER_CAP_VALUE                 (key_touch_dsRam.wdgtList.button10.fingerCap)
#define key_touch_BUTTON10_FINGER_CAP_OFFSET                (230u)
#define key_touch_BUTTON10_FINGER_CAP_SIZE                  (2u)
#define key_touch_BUTTON10_FINGER_CAP_PARAM_ID              (0xA20A00E6u)

#define key_touch_BUTTON10_SIGPFC_VALUE                     (key_touch_dsRam.wdgtList.button10.sigPFC)
#define key_touch_BUTTON10_SIGPFC_OFFSET                    (232u)
#define key_touch_BUTTON10_SIGPFC_SIZE                      (2u)
#define key_touch_BUTTON10_SIGPFC_PARAM_ID                  (0xAD0A00E8u)

#define key_touch_BUTTON11_RESOLUTION_VALUE                 (key_touch_dsRam.wdgtList.button11.resolution)
#define key_touch_BUTTON11_RESOLUTION_OFFSET                (234u)
#define key_touch_BUTTON11_RESOLUTION_SIZE                  (2u)
#define key_touch_BUTTON11_RESOLUTION_PARAM_ID              (0x848B00EAu)

#define key_touch_BUTTON11_FINGER_TH_VALUE                  (key_touch_dsRam.wdgtList.button11.fingerTh)
#define key_touch_BUTTON11_FINGER_TH_OFFSET                 (236u)
#define key_touch_BUTTON11_FINGER_TH_SIZE                   (2u)
#define key_touch_BUTTON11_FINGER_TH_PARAM_ID               (0x898B00ECu)

#define key_touch_BUTTON11_NOISE_TH_VALUE                   (key_touch_dsRam.wdgtList.button11.noiseTh)
#define key_touch_BUTTON11_NOISE_TH_OFFSET                  (238u)
#define key_touch_BUTTON11_NOISE_TH_SIZE                    (1u)
#define key_touch_BUTTON11_NOISE_TH_PARAM_ID                (0x4D8B00EEu)

#define key_touch_BUTTON11_NNOISE_TH_VALUE                  (key_touch_dsRam.wdgtList.button11.nNoiseTh)
#define key_touch_BUTTON11_NNOISE_TH_OFFSET                 (239u)
#define key_touch_BUTTON11_NNOISE_TH_SIZE                   (1u)
#define key_touch_BUTTON11_NNOISE_TH_PARAM_ID               (0x4B8B00EFu)

#define key_touch_BUTTON11_HYSTERESIS_VALUE                 (key_touch_dsRam.wdgtList.button11.hysteresis)
#define key_touch_BUTTON11_HYSTERESIS_OFFSET                (240u)
#define key_touch_BUTTON11_HYSTERESIS_SIZE                  (1u)
#define key_touch_BUTTON11_HYSTERESIS_PARAM_ID              (0x478B00F0u)

#define key_touch_BUTTON11_ON_DEBOUNCE_VALUE                (key_touch_dsRam.wdgtList.button11.onDebounce)
#define key_touch_BUTTON11_ON_DEBOUNCE_OFFSET               (241u)
#define key_touch_BUTTON11_ON_DEBOUNCE_SIZE                 (1u)
#define key_touch_BUTTON11_ON_DEBOUNCE_PARAM_ID             (0x418B00F1u)

#define key_touch_BUTTON11_LOW_BSLN_RST_VALUE               (key_touch_dsRam.wdgtList.button11.lowBslnRst)
#define key_touch_BUTTON11_LOW_BSLN_RST_OFFSET              (242u)
#define key_touch_BUTTON11_LOW_BSLN_RST_SIZE                (1u)
#define key_touch_BUTTON11_LOW_BSLN_RST_PARAM_ID            (0x4B8B00F2u)

#define key_touch_BUTTON11_BSLN_COEFF_VALUE                 (key_touch_dsRam.wdgtList.button11.bslnCoeff)
#define key_touch_BUTTON11_BSLN_COEFF_OFFSET                (243u)
#define key_touch_BUTTON11_BSLN_COEFF_SIZE                  (1u)
#define key_touch_BUTTON11_BSLN_COEFF_PARAM_ID              (0x668B00F3u)

#define key_touch_BUTTON11_IDAC_MOD0_VALUE                  (key_touch_dsRam.wdgtList.button11.idacMod[0u])
#define key_touch_BUTTON11_IDAC_MOD0_OFFSET                 (244u)
#define key_touch_BUTTON11_IDAC_MOD0_SIZE                   (1u)
#define key_touch_BUTTON11_IDAC_MOD0_PARAM_ID               (0x4B0B00F4u)

#define key_touch_BUTTON11_SNS_CLK_VALUE                    (key_touch_dsRam.wdgtList.button11.snsClk)
#define key_touch_BUTTON11_SNS_CLK_OFFSET                   (245u)
#define key_touch_BUTTON11_SNS_CLK_SIZE                     (1u)
#define key_touch_BUTTON11_SNS_CLK_PARAM_ID                 (0x408B00F5u)

#define key_touch_BUTTON11_SNS_CLK_SOURCE_VALUE             (key_touch_dsRam.wdgtList.button11.snsClkSource)
#define key_touch_BUTTON11_SNS_CLK_SOURCE_OFFSET            (246u)
#define key_touch_BUTTON11_SNS_CLK_SOURCE_SIZE              (1u)
#define key_touch_BUTTON11_SNS_CLK_SOURCE_PARAM_ID          (0x4A8B00F6u)

#define key_touch_BUTTON11_FINGER_CAP_VALUE                 (key_touch_dsRam.wdgtList.button11.fingerCap)
#define key_touch_BUTTON11_FINGER_CAP_OFFSET                (248u)
#define key_touch_BUTTON11_FINGER_CAP_SIZE                  (2u)
#define key_touch_BUTTON11_FINGER_CAP_PARAM_ID              (0xAB0B00F8u)

#define key_touch_BUTTON11_SIGPFC_VALUE                     (key_touch_dsRam.wdgtList.button11.sigPFC)
#define key_touch_BUTTON11_SIGPFC_OFFSET                    (250u)
#define key_touch_BUTTON11_SIGPFC_SIZE                      (2u)
#define key_touch_BUTTON11_SIGPFC_PARAM_ID                  (0xA70B00FAu)

#define key_touch_BUTTON0_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button0[0u].raw[0u])
#define key_touch_BUTTON0_SNS0_RAW0_OFFSET                  (252u)
#define key_touch_BUTTON0_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON0_SNS0_RAW0_PARAM_ID                (0x850000FCu)

#define key_touch_BUTTON0_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button0[0u].bsln[0u])
#define key_touch_BUTTON0_SNS0_BSLN0_OFFSET                 (254u)
#define key_touch_BUTTON0_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON0_SNS0_BSLN0_PARAM_ID               (0x890000FEu)

#define key_touch_BUTTON0_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button0[0u].bslnExt[0u])
#define key_touch_BUTTON0_SNS0_BSLN_EXT0_OFFSET             (256u)
#define key_touch_BUTTON0_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON0_SNS0_BSLN_EXT0_PARAM_ID           (0x44000100u)

#define key_touch_BUTTON0_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button0[0u].diff)
#define key_touch_BUTTON0_SNS0_DIFF_OFFSET                  (258u)
#define key_touch_BUTTON0_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON0_SNS0_DIFF_PARAM_ID                (0x80000102u)

#define key_touch_BUTTON0_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button0[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON0_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (260u)
#define key_touch_BUTTON0_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON0_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x45000104u)

#define key_touch_BUTTON0_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button0[0u].idacComp[0u])
#define key_touch_BUTTON0_SNS0_IDAC_COMP0_OFFSET            (261u)
#define key_touch_BUTTON0_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON0_SNS0_IDAC_COMP0_PARAM_ID          (0x43000105u)

#define key_touch_BUTTON1_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button1[0u].raw[0u])
#define key_touch_BUTTON1_SNS0_RAW0_OFFSET                  (262u)
#define key_touch_BUTTON1_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON1_SNS0_RAW0_PARAM_ID                (0x81000106u)

#define key_touch_BUTTON1_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button1[0u].bsln[0u])
#define key_touch_BUTTON1_SNS0_BSLN0_OFFSET                 (264u)
#define key_touch_BUTTON1_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON1_SNS0_BSLN0_PARAM_ID               (0x8E000108u)

#define key_touch_BUTTON1_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button1[0u].bslnExt[0u])
#define key_touch_BUTTON1_SNS0_BSLN_EXT0_OFFSET             (266u)
#define key_touch_BUTTON1_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON1_SNS0_BSLN_EXT0_PARAM_ID           (0x4A00010Au)

#define key_touch_BUTTON1_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button1[0u].diff)
#define key_touch_BUTTON1_SNS0_DIFF_OFFSET                  (268u)
#define key_touch_BUTTON1_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON1_SNS0_DIFF_PARAM_ID                (0x8F00010Cu)

#define key_touch_BUTTON1_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button1[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON1_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (270u)
#define key_touch_BUTTON1_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON1_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4B00010Eu)

#define key_touch_BUTTON1_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button1[0u].idacComp[0u])
#define key_touch_BUTTON1_SNS0_IDAC_COMP0_OFFSET            (271u)
#define key_touch_BUTTON1_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON1_SNS0_IDAC_COMP0_PARAM_ID          (0x4D00010Fu)

#define key_touch_BUTTON2_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button2[0u].raw[0u])
#define key_touch_BUTTON2_SNS0_RAW0_OFFSET                  (272u)
#define key_touch_BUTTON2_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON2_SNS0_RAW0_PARAM_ID                (0x89000110u)

#define key_touch_BUTTON2_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button2[0u].bsln[0u])
#define key_touch_BUTTON2_SNS0_BSLN0_OFFSET                 (274u)
#define key_touch_BUTTON2_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON2_SNS0_BSLN0_PARAM_ID               (0x85000112u)

#define key_touch_BUTTON2_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button2[0u].bslnExt[0u])
#define key_touch_BUTTON2_SNS0_BSLN_EXT0_OFFSET             (276u)
#define key_touch_BUTTON2_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON2_SNS0_BSLN_EXT0_PARAM_ID           (0x40000114u)

#define key_touch_BUTTON2_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button2[0u].diff)
#define key_touch_BUTTON2_SNS0_DIFF_OFFSET                  (278u)
#define key_touch_BUTTON2_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON2_SNS0_DIFF_PARAM_ID                (0x84000116u)

#define key_touch_BUTTON2_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button2[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON2_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (280u)
#define key_touch_BUTTON2_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON2_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x43000118u)

#define key_touch_BUTTON2_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button2[0u].idacComp[0u])
#define key_touch_BUTTON2_SNS0_IDAC_COMP0_OFFSET            (281u)
#define key_touch_BUTTON2_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON2_SNS0_IDAC_COMP0_PARAM_ID          (0x45000119u)

#define key_touch_BUTTON3_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button3[0u].raw[0u])
#define key_touch_BUTTON3_SNS0_RAW0_OFFSET                  (282u)
#define key_touch_BUTTON3_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON3_SNS0_RAW0_PARAM_ID                (0x8700011Au)

#define key_touch_BUTTON3_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button3[0u].bsln[0u])
#define key_touch_BUTTON3_SNS0_BSLN0_OFFSET                 (284u)
#define key_touch_BUTTON3_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON3_SNS0_BSLN0_PARAM_ID               (0x8A00011Cu)

#define key_touch_BUTTON3_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button3[0u].bslnExt[0u])
#define key_touch_BUTTON3_SNS0_BSLN_EXT0_OFFSET             (286u)
#define key_touch_BUTTON3_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON3_SNS0_BSLN_EXT0_PARAM_ID           (0x4E00011Eu)

#define key_touch_BUTTON3_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button3[0u].diff)
#define key_touch_BUTTON3_SNS0_DIFF_OFFSET                  (288u)
#define key_touch_BUTTON3_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON3_SNS0_DIFF_PARAM_ID                (0x86000120u)

#define key_touch_BUTTON3_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button3[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON3_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (290u)
#define key_touch_BUTTON3_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON3_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x42000122u)

#define key_touch_BUTTON3_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button3[0u].idacComp[0u])
#define key_touch_BUTTON3_SNS0_IDAC_COMP0_OFFSET            (291u)
#define key_touch_BUTTON3_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON3_SNS0_IDAC_COMP0_PARAM_ID          (0x44000123u)

#define key_touch_BUTTON4_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button4[0u].raw[0u])
#define key_touch_BUTTON4_SNS0_RAW0_OFFSET                  (292u)
#define key_touch_BUTTON4_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON4_SNS0_RAW0_PARAM_ID                (0x87000124u)

#define key_touch_BUTTON4_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button4[0u].bsln[0u])
#define key_touch_BUTTON4_SNS0_BSLN0_OFFSET                 (294u)
#define key_touch_BUTTON4_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON4_SNS0_BSLN0_PARAM_ID               (0x8B000126u)

#define key_touch_BUTTON4_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button4[0u].bslnExt[0u])
#define key_touch_BUTTON4_SNS0_BSLN_EXT0_OFFSET             (296u)
#define key_touch_BUTTON4_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON4_SNS0_BSLN_EXT0_PARAM_ID           (0x4C000128u)

#define key_touch_BUTTON4_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button4[0u].diff)
#define key_touch_BUTTON4_SNS0_DIFF_OFFSET                  (298u)
#define key_touch_BUTTON4_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON4_SNS0_DIFF_PARAM_ID                (0x8800012Au)

#define key_touch_BUTTON4_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button4[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON4_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (300u)
#define key_touch_BUTTON4_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON4_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4D00012Cu)

#define key_touch_BUTTON4_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button4[0u].idacComp[0u])
#define key_touch_BUTTON4_SNS0_IDAC_COMP0_OFFSET            (301u)
#define key_touch_BUTTON4_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON4_SNS0_IDAC_COMP0_PARAM_ID          (0x4B00012Du)

#define key_touch_BUTTON5_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button5[0u].raw[0u])
#define key_touch_BUTTON5_SNS0_RAW0_OFFSET                  (302u)
#define key_touch_BUTTON5_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON5_SNS0_RAW0_PARAM_ID                (0x8900012Eu)

#define key_touch_BUTTON5_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button5[0u].bsln[0u])
#define key_touch_BUTTON5_SNS0_BSLN0_OFFSET                 (304u)
#define key_touch_BUTTON5_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON5_SNS0_BSLN0_PARAM_ID               (0x83000130u)

#define key_touch_BUTTON5_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button5[0u].bslnExt[0u])
#define key_touch_BUTTON5_SNS0_BSLN_EXT0_OFFSET             (306u)
#define key_touch_BUTTON5_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON5_SNS0_BSLN_EXT0_PARAM_ID           (0x47000132u)

#define key_touch_BUTTON5_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button5[0u].diff)
#define key_touch_BUTTON5_SNS0_DIFF_OFFSET                  (308u)
#define key_touch_BUTTON5_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON5_SNS0_DIFF_PARAM_ID                (0x82000134u)

#define key_touch_BUTTON5_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button5[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON5_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (310u)
#define key_touch_BUTTON5_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON5_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x46000136u)

#define key_touch_BUTTON5_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button5[0u].idacComp[0u])
#define key_touch_BUTTON5_SNS0_IDAC_COMP0_OFFSET            (311u)
#define key_touch_BUTTON5_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON5_SNS0_IDAC_COMP0_PARAM_ID          (0x40000137u)

#define key_touch_BUTTON6_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button6[0u].raw[0u])
#define key_touch_BUTTON6_SNS0_RAW0_OFFSET                  (312u)
#define key_touch_BUTTON6_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON6_SNS0_RAW0_PARAM_ID                (0x81000138u)

#define key_touch_BUTTON6_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button6[0u].bsln[0u])
#define key_touch_BUTTON6_SNS0_BSLN0_OFFSET                 (314u)
#define key_touch_BUTTON6_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON6_SNS0_BSLN0_PARAM_ID               (0x8D00013Au)

#define key_touch_BUTTON6_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button6[0u].bslnExt[0u])
#define key_touch_BUTTON6_SNS0_BSLN_EXT0_OFFSET             (316u)
#define key_touch_BUTTON6_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON6_SNS0_BSLN_EXT0_PARAM_ID           (0x4800013Cu)

#define key_touch_BUTTON6_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button6[0u].diff)
#define key_touch_BUTTON6_SNS0_DIFF_OFFSET                  (318u)
#define key_touch_BUTTON6_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON6_SNS0_DIFF_PARAM_ID                (0x8C00013Eu)

#define key_touch_BUTTON6_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button6[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON6_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (320u)
#define key_touch_BUTTON6_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON6_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x49000140u)

#define key_touch_BUTTON6_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button6[0u].idacComp[0u])
#define key_touch_BUTTON6_SNS0_IDAC_COMP0_OFFSET            (321u)
#define key_touch_BUTTON6_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON6_SNS0_IDAC_COMP0_PARAM_ID          (0x4F000141u)

#define key_touch_BUTTON7_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button7[0u].raw[0u])
#define key_touch_BUTTON7_SNS0_RAW0_OFFSET                  (322u)
#define key_touch_BUTTON7_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON7_SNS0_RAW0_PARAM_ID                (0x8D000142u)

#define key_touch_BUTTON7_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button7[0u].bsln[0u])
#define key_touch_BUTTON7_SNS0_BSLN0_OFFSET                 (324u)
#define key_touch_BUTTON7_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON7_SNS0_BSLN0_PARAM_ID               (0x80000144u)

#define key_touch_BUTTON7_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button7[0u].bslnExt[0u])
#define key_touch_BUTTON7_SNS0_BSLN_EXT0_OFFSET             (326u)
#define key_touch_BUTTON7_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON7_SNS0_BSLN_EXT0_PARAM_ID           (0x44000146u)

#define key_touch_BUTTON7_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button7[0u].diff)
#define key_touch_BUTTON7_SNS0_DIFF_OFFSET                  (328u)
#define key_touch_BUTTON7_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON7_SNS0_DIFF_PARAM_ID                (0x83000148u)

#define key_touch_BUTTON7_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button7[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON7_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (330u)
#define key_touch_BUTTON7_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON7_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4700014Au)

#define key_touch_BUTTON7_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button7[0u].idacComp[0u])
#define key_touch_BUTTON7_SNS0_IDAC_COMP0_OFFSET            (331u)
#define key_touch_BUTTON7_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON7_SNS0_IDAC_COMP0_PARAM_ID          (0x4100014Bu)

#define key_touch_BUTTON8_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button8[0u].raw[0u])
#define key_touch_BUTTON8_SNS0_RAW0_OFFSET                  (332u)
#define key_touch_BUTTON8_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON8_SNS0_RAW0_PARAM_ID                (0x8200014Cu)

#define key_touch_BUTTON8_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button8[0u].bsln[0u])
#define key_touch_BUTTON8_SNS0_BSLN0_OFFSET                 (334u)
#define key_touch_BUTTON8_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON8_SNS0_BSLN0_PARAM_ID               (0x8E00014Eu)

#define key_touch_BUTTON8_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button8[0u].bslnExt[0u])
#define key_touch_BUTTON8_SNS0_BSLN_EXT0_OFFSET             (336u)
#define key_touch_BUTTON8_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON8_SNS0_BSLN_EXT0_PARAM_ID           (0x4C000150u)

#define key_touch_BUTTON8_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button8[0u].diff)
#define key_touch_BUTTON8_SNS0_DIFF_OFFSET                  (338u)
#define key_touch_BUTTON8_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON8_SNS0_DIFF_PARAM_ID                (0x88000152u)

#define key_touch_BUTTON8_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button8[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON8_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (340u)
#define key_touch_BUTTON8_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON8_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4D000154u)

#define key_touch_BUTTON8_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button8[0u].idacComp[0u])
#define key_touch_BUTTON8_SNS0_IDAC_COMP0_OFFSET            (341u)
#define key_touch_BUTTON8_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON8_SNS0_IDAC_COMP0_PARAM_ID          (0x4B000155u)

#define key_touch_BUTTON9_SNS0_RAW0_VALUE                   (key_touch_dsRam.snsList.button9[0u].raw[0u])
#define key_touch_BUTTON9_SNS0_RAW0_OFFSET                  (342u)
#define key_touch_BUTTON9_SNS0_RAW0_SIZE                    (2u)
#define key_touch_BUTTON9_SNS0_RAW0_PARAM_ID                (0x89000156u)

#define key_touch_BUTTON9_SNS0_BSLN0_VALUE                  (key_touch_dsRam.snsList.button9[0u].bsln[0u])
#define key_touch_BUTTON9_SNS0_BSLN0_OFFSET                 (344u)
#define key_touch_BUTTON9_SNS0_BSLN0_SIZE                   (2u)
#define key_touch_BUTTON9_SNS0_BSLN0_PARAM_ID               (0x86000158u)

#define key_touch_BUTTON9_SNS0_BSLN_EXT0_VALUE              (key_touch_dsRam.snsList.button9[0u].bslnExt[0u])
#define key_touch_BUTTON9_SNS0_BSLN_EXT0_OFFSET             (346u)
#define key_touch_BUTTON9_SNS0_BSLN_EXT0_SIZE               (1u)
#define key_touch_BUTTON9_SNS0_BSLN_EXT0_PARAM_ID           (0x4200015Au)

#define key_touch_BUTTON9_SNS0_DIFF_VALUE                   (key_touch_dsRam.snsList.button9[0u].diff)
#define key_touch_BUTTON9_SNS0_DIFF_OFFSET                  (348u)
#define key_touch_BUTTON9_SNS0_DIFF_SIZE                    (2u)
#define key_touch_BUTTON9_SNS0_DIFF_PARAM_ID                (0x8700015Cu)

#define key_touch_BUTTON9_SNS0_NEG_BSLN_RST_CNT0_VALUE      (key_touch_dsRam.snsList.button9[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON9_SNS0_NEG_BSLN_RST_CNT0_OFFSET     (350u)
#define key_touch_BUTTON9_SNS0_NEG_BSLN_RST_CNT0_SIZE       (1u)
#define key_touch_BUTTON9_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID   (0x4300015Eu)

#define key_touch_BUTTON9_SNS0_IDAC_COMP0_VALUE             (key_touch_dsRam.snsList.button9[0u].idacComp[0u])
#define key_touch_BUTTON9_SNS0_IDAC_COMP0_OFFSET            (351u)
#define key_touch_BUTTON9_SNS0_IDAC_COMP0_SIZE              (1u)
#define key_touch_BUTTON9_SNS0_IDAC_COMP0_PARAM_ID          (0x4500015Fu)

#define key_touch_BUTTON10_SNS0_RAW0_VALUE                  (key_touch_dsRam.snsList.button10[0u].raw[0u])
#define key_touch_BUTTON10_SNS0_RAW0_OFFSET                 (352u)
#define key_touch_BUTTON10_SNS0_RAW0_SIZE                   (2u)
#define key_touch_BUTTON10_SNS0_RAW0_PARAM_ID               (0x8B000160u)

#define key_touch_BUTTON10_SNS0_BSLN0_VALUE                 (key_touch_dsRam.snsList.button10[0u].bsln[0u])
#define key_touch_BUTTON10_SNS0_BSLN0_OFFSET                (354u)
#define key_touch_BUTTON10_SNS0_BSLN0_SIZE                  (2u)
#define key_touch_BUTTON10_SNS0_BSLN0_PARAM_ID              (0x87000162u)

#define key_touch_BUTTON10_SNS0_BSLN_EXT0_VALUE             (key_touch_dsRam.snsList.button10[0u].bslnExt[0u])
#define key_touch_BUTTON10_SNS0_BSLN_EXT0_OFFSET            (356u)
#define key_touch_BUTTON10_SNS0_BSLN_EXT0_SIZE              (1u)
#define key_touch_BUTTON10_SNS0_BSLN_EXT0_PARAM_ID          (0x42000164u)

#define key_touch_BUTTON10_SNS0_DIFF_VALUE                  (key_touch_dsRam.snsList.button10[0u].diff)
#define key_touch_BUTTON10_SNS0_DIFF_OFFSET                 (358u)
#define key_touch_BUTTON10_SNS0_DIFF_SIZE                   (2u)
#define key_touch_BUTTON10_SNS0_DIFF_PARAM_ID               (0x86000166u)

#define key_touch_BUTTON10_SNS0_NEG_BSLN_RST_CNT0_VALUE     (key_touch_dsRam.snsList.button10[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON10_SNS0_NEG_BSLN_RST_CNT0_OFFSET    (360u)
#define key_touch_BUTTON10_SNS0_NEG_BSLN_RST_CNT0_SIZE      (1u)
#define key_touch_BUTTON10_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID  (0x41000168u)

#define key_touch_BUTTON10_SNS0_IDAC_COMP0_VALUE            (key_touch_dsRam.snsList.button10[0u].idacComp[0u])
#define key_touch_BUTTON10_SNS0_IDAC_COMP0_OFFSET           (361u)
#define key_touch_BUTTON10_SNS0_IDAC_COMP0_SIZE             (1u)
#define key_touch_BUTTON10_SNS0_IDAC_COMP0_PARAM_ID         (0x47000169u)

#define key_touch_BUTTON11_SNS0_RAW0_VALUE                  (key_touch_dsRam.snsList.button11[0u].raw[0u])
#define key_touch_BUTTON11_SNS0_RAW0_OFFSET                 (362u)
#define key_touch_BUTTON11_SNS0_RAW0_SIZE                   (2u)
#define key_touch_BUTTON11_SNS0_RAW0_PARAM_ID               (0x8500016Au)

#define key_touch_BUTTON11_SNS0_BSLN0_VALUE                 (key_touch_dsRam.snsList.button11[0u].bsln[0u])
#define key_touch_BUTTON11_SNS0_BSLN0_OFFSET                (364u)
#define key_touch_BUTTON11_SNS0_BSLN0_SIZE                  (2u)
#define key_touch_BUTTON11_SNS0_BSLN0_PARAM_ID              (0x8800016Cu)

#define key_touch_BUTTON11_SNS0_BSLN_EXT0_VALUE             (key_touch_dsRam.snsList.button11[0u].bslnExt[0u])
#define key_touch_BUTTON11_SNS0_BSLN_EXT0_OFFSET            (366u)
#define key_touch_BUTTON11_SNS0_BSLN_EXT0_SIZE              (1u)
#define key_touch_BUTTON11_SNS0_BSLN_EXT0_PARAM_ID          (0x4C00016Eu)

#define key_touch_BUTTON11_SNS0_DIFF_VALUE                  (key_touch_dsRam.snsList.button11[0u].diff)
#define key_touch_BUTTON11_SNS0_DIFF_OFFSET                 (368u)
#define key_touch_BUTTON11_SNS0_DIFF_SIZE                   (2u)
#define key_touch_BUTTON11_SNS0_DIFF_PARAM_ID               (0x8E000170u)

#define key_touch_BUTTON11_SNS0_NEG_BSLN_RST_CNT0_VALUE     (key_touch_dsRam.snsList.button11[0u].negBslnRstCnt[0u])
#define key_touch_BUTTON11_SNS0_NEG_BSLN_RST_CNT0_OFFSET    (370u)
#define key_touch_BUTTON11_SNS0_NEG_BSLN_RST_CNT0_SIZE      (1u)
#define key_touch_BUTTON11_SNS0_NEG_BSLN_RST_CNT0_PARAM_ID  (0x4A000172u)

#define key_touch_BUTTON11_SNS0_IDAC_COMP0_VALUE            (key_touch_dsRam.snsList.button11[0u].idacComp[0u])
#define key_touch_BUTTON11_SNS0_IDAC_COMP0_OFFSET           (371u)
#define key_touch_BUTTON11_SNS0_IDAC_COMP0_SIZE             (1u)
#define key_touch_BUTTON11_SNS0_IDAC_COMP0_PARAM_ID         (0x4C000173u)

#define key_touch_SNR_TEST_WIDGET_ID_VALUE                  (key_touch_dsRam.snrTestWidgetId)
#define key_touch_SNR_TEST_WIDGET_ID_OFFSET                 (372u)
#define key_touch_SNR_TEST_WIDGET_ID_SIZE                   (1u)
#define key_touch_SNR_TEST_WIDGET_ID_PARAM_ID               (0x6C000174u)

#define key_touch_SNR_TEST_SENSOR_ID_VALUE                  (key_touch_dsRam.snrTestSensorId)
#define key_touch_SNR_TEST_SENSOR_ID_OFFSET                 (373u)
#define key_touch_SNR_TEST_SENSOR_ID_SIZE                   (1u)
#define key_touch_SNR_TEST_SENSOR_ID_PARAM_ID               (0x6A000175u)

#define key_touch_SNR_TEST_SCAN_COUNTER_VALUE               (key_touch_dsRam.snrTestScanCounter)
#define key_touch_SNR_TEST_SCAN_COUNTER_OFFSET              (374u)
#define key_touch_SNR_TEST_SCAN_COUNTER_SIZE                (2u)
#define key_touch_SNR_TEST_SCAN_COUNTER_PARAM_ID            (0x83000176u)

#define key_touch_SNR_TEST_RAW_COUNT0_VALUE                 (key_touch_dsRam.snrTestRawCount[0u])
#define key_touch_SNR_TEST_RAW_COUNT0_OFFSET                (376u)
#define key_touch_SNR_TEST_RAW_COUNT0_SIZE                  (2u)
#define key_touch_SNR_TEST_RAW_COUNT0_PARAM_ID              (0x8C000178u)


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

#define key_touch_BUTTON0_PTR2NOISE_ENVLP_VALUE             (key_touch_dsFlash.wdgtArray[0].ptr2NoiseEnvlp)
#define key_touch_BUTTON0_PTR2NOISE_ENVLP_OFFSET            (28u)
#define key_touch_BUTTON0_PTR2NOISE_ENVLP_SIZE              (4u)
#define key_touch_BUTTON0_PTR2NOISE_ENVLP_PARAM_ID          (0xD700001Cu)

#define key_touch_BUTTON1_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[1].ptr2SnsFlash)
#define key_touch_BUTTON1_PTR2SNS_FLASH_OFFSET              (32u)
#define key_touch_BUTTON1_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON1_PTR2SNS_FLASH_PARAM_ID            (0xD8010020u)

#define key_touch_BUTTON1_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[1].ptr2WdgtRam)
#define key_touch_BUTTON1_PTR2WD_RAM_OFFSET                 (36u)
#define key_touch_BUTTON1_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON1_PTR2WD_RAM_PARAM_ID               (0xD9010024u)

#define key_touch_BUTTON1_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[1].ptr2SnsRam)
#define key_touch_BUTTON1_PTR2SNS_RAM_OFFSET                (40u)
#define key_touch_BUTTON1_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON1_PTR2SNS_RAM_PARAM_ID              (0xDA010028u)

#define key_touch_BUTTON1_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[1].ptr2FltrHistory)
#define key_touch_BUTTON1_PTR2FLTR_HISTORY_OFFSET           (44u)
#define key_touch_BUTTON1_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON1_PTR2FLTR_HISTORY_PARAM_ID         (0xDB01002Cu)

#define key_touch_BUTTON1_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[1].ptr2DebounceArr)
#define key_touch_BUTTON1_PTR2DEBOUNCE_OFFSET               (48u)
#define key_touch_BUTTON1_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON1_PTR2DEBOUNCE_PARAM_ID             (0xDD010030u)

#define key_touch_BUTTON1_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[1].staticConfig)
#define key_touch_BUTTON1_STATIC_CONFIG_OFFSET              (52u)
#define key_touch_BUTTON1_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON1_STATIC_CONFIG_PARAM_ID            (0x93010034u)

#define key_touch_BUTTON1_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[1].totalNumSns)
#define key_touch_BUTTON1_TOTAL_NUM_SNS_OFFSET              (54u)
#define key_touch_BUTTON1_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON1_TOTAL_NUM_SNS_PARAM_ID            (0x9F010036u)

#define key_touch_BUTTON1_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[1].wdgtType)
#define key_touch_BUTTON1_TYPE_OFFSET                       (56u)
#define key_touch_BUTTON1_TYPE_SIZE                         (1u)
#define key_touch_BUTTON1_TYPE_PARAM_ID                     (0x58010038u)

#define key_touch_BUTTON1_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[1].numCols)
#define key_touch_BUTTON1_NUM_COLS_OFFSET                   (57u)
#define key_touch_BUTTON1_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON1_NUM_COLS_PARAM_ID                 (0x5E010039u)

#define key_touch_BUTTON1_PTR2NOISE_ENVLP_VALUE             (key_touch_dsFlash.wdgtArray[1].ptr2NoiseEnvlp)
#define key_touch_BUTTON1_PTR2NOISE_ENVLP_OFFSET            (60u)
#define key_touch_BUTTON1_PTR2NOISE_ENVLP_SIZE              (4u)
#define key_touch_BUTTON1_PTR2NOISE_ENVLP_PARAM_ID          (0xDE01003Cu)

#define key_touch_BUTTON2_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[2].ptr2SnsFlash)
#define key_touch_BUTTON2_PTR2SNS_FLASH_OFFSET              (64u)
#define key_touch_BUTTON2_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON2_PTR2SNS_FLASH_PARAM_ID            (0xDA020040u)

#define key_touch_BUTTON2_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[2].ptr2WdgtRam)
#define key_touch_BUTTON2_PTR2WD_RAM_OFFSET                 (68u)
#define key_touch_BUTTON2_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON2_PTR2WD_RAM_PARAM_ID               (0xDB020044u)

#define key_touch_BUTTON2_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[2].ptr2SnsRam)
#define key_touch_BUTTON2_PTR2SNS_RAM_OFFSET                (72u)
#define key_touch_BUTTON2_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON2_PTR2SNS_RAM_PARAM_ID              (0xD8020048u)

#define key_touch_BUTTON2_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[2].ptr2FltrHistory)
#define key_touch_BUTTON2_PTR2FLTR_HISTORY_OFFSET           (76u)
#define key_touch_BUTTON2_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON2_PTR2FLTR_HISTORY_PARAM_ID         (0xD902004Cu)

#define key_touch_BUTTON2_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[2].ptr2DebounceArr)
#define key_touch_BUTTON2_PTR2DEBOUNCE_OFFSET               (80u)
#define key_touch_BUTTON2_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON2_PTR2DEBOUNCE_PARAM_ID             (0xDF020050u)

#define key_touch_BUTTON2_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[2].staticConfig)
#define key_touch_BUTTON2_STATIC_CONFIG_OFFSET              (84u)
#define key_touch_BUTTON2_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON2_STATIC_CONFIG_PARAM_ID            (0x91020054u)

#define key_touch_BUTTON2_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[2].totalNumSns)
#define key_touch_BUTTON2_TOTAL_NUM_SNS_OFFSET              (86u)
#define key_touch_BUTTON2_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON2_TOTAL_NUM_SNS_PARAM_ID            (0x9D020056u)

#define key_touch_BUTTON2_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[2].wdgtType)
#define key_touch_BUTTON2_TYPE_OFFSET                       (88u)
#define key_touch_BUTTON2_TYPE_SIZE                         (1u)
#define key_touch_BUTTON2_TYPE_PARAM_ID                     (0x5A020058u)

#define key_touch_BUTTON2_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[2].numCols)
#define key_touch_BUTTON2_NUM_COLS_OFFSET                   (89u)
#define key_touch_BUTTON2_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON2_NUM_COLS_PARAM_ID                 (0x5C020059u)

#define key_touch_BUTTON2_PTR2NOISE_ENVLP_VALUE             (key_touch_dsFlash.wdgtArray[2].ptr2NoiseEnvlp)
#define key_touch_BUTTON2_PTR2NOISE_ENVLP_OFFSET            (92u)
#define key_touch_BUTTON2_PTR2NOISE_ENVLP_SIZE              (4u)
#define key_touch_BUTTON2_PTR2NOISE_ENVLP_PARAM_ID          (0xDC02005Cu)

#define key_touch_BUTTON3_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[3].ptr2SnsFlash)
#define key_touch_BUTTON3_PTR2SNS_FLASH_OFFSET              (96u)
#define key_touch_BUTTON3_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON3_PTR2SNS_FLASH_PARAM_ID            (0xD3030060u)

#define key_touch_BUTTON3_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[3].ptr2WdgtRam)
#define key_touch_BUTTON3_PTR2WD_RAM_OFFSET                 (100u)
#define key_touch_BUTTON3_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON3_PTR2WD_RAM_PARAM_ID               (0xD2030064u)

#define key_touch_BUTTON3_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[3].ptr2SnsRam)
#define key_touch_BUTTON3_PTR2SNS_RAM_OFFSET                (104u)
#define key_touch_BUTTON3_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON3_PTR2SNS_RAM_PARAM_ID              (0xD1030068u)

#define key_touch_BUTTON3_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[3].ptr2FltrHistory)
#define key_touch_BUTTON3_PTR2FLTR_HISTORY_OFFSET           (108u)
#define key_touch_BUTTON3_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON3_PTR2FLTR_HISTORY_PARAM_ID         (0xD003006Cu)

#define key_touch_BUTTON3_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[3].ptr2DebounceArr)
#define key_touch_BUTTON3_PTR2DEBOUNCE_OFFSET               (112u)
#define key_touch_BUTTON3_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON3_PTR2DEBOUNCE_PARAM_ID             (0xD6030070u)

#define key_touch_BUTTON3_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[3].staticConfig)
#define key_touch_BUTTON3_STATIC_CONFIG_OFFSET              (116u)
#define key_touch_BUTTON3_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON3_STATIC_CONFIG_PARAM_ID            (0x98030074u)

#define key_touch_BUTTON3_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[3].totalNumSns)
#define key_touch_BUTTON3_TOTAL_NUM_SNS_OFFSET              (118u)
#define key_touch_BUTTON3_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON3_TOTAL_NUM_SNS_PARAM_ID            (0x94030076u)

#define key_touch_BUTTON3_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[3].wdgtType)
#define key_touch_BUTTON3_TYPE_OFFSET                       (120u)
#define key_touch_BUTTON3_TYPE_SIZE                         (1u)
#define key_touch_BUTTON3_TYPE_PARAM_ID                     (0x53030078u)

#define key_touch_BUTTON3_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[3].numCols)
#define key_touch_BUTTON3_NUM_COLS_OFFSET                   (121u)
#define key_touch_BUTTON3_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON3_NUM_COLS_PARAM_ID                 (0x55030079u)

#define key_touch_BUTTON3_PTR2NOISE_ENVLP_VALUE             (key_touch_dsFlash.wdgtArray[3].ptr2NoiseEnvlp)
#define key_touch_BUTTON3_PTR2NOISE_ENVLP_OFFSET            (124u)
#define key_touch_BUTTON3_PTR2NOISE_ENVLP_SIZE              (4u)
#define key_touch_BUTTON3_PTR2NOISE_ENVLP_PARAM_ID          (0xD503007Cu)

#define key_touch_BUTTON4_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[4].ptr2SnsFlash)
#define key_touch_BUTTON4_PTR2SNS_FLASH_OFFSET              (128u)
#define key_touch_BUTTON4_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON4_PTR2SNS_FLASH_PARAM_ID            (0xDE040080u)

#define key_touch_BUTTON4_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[4].ptr2WdgtRam)
#define key_touch_BUTTON4_PTR2WD_RAM_OFFSET                 (132u)
#define key_touch_BUTTON4_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON4_PTR2WD_RAM_PARAM_ID               (0xDF040084u)

#define key_touch_BUTTON4_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[4].ptr2SnsRam)
#define key_touch_BUTTON4_PTR2SNS_RAM_OFFSET                (136u)
#define key_touch_BUTTON4_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON4_PTR2SNS_RAM_PARAM_ID              (0xDC040088u)

#define key_touch_BUTTON4_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[4].ptr2FltrHistory)
#define key_touch_BUTTON4_PTR2FLTR_HISTORY_OFFSET           (140u)
#define key_touch_BUTTON4_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON4_PTR2FLTR_HISTORY_PARAM_ID         (0xDD04008Cu)

#define key_touch_BUTTON4_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[4].ptr2DebounceArr)
#define key_touch_BUTTON4_PTR2DEBOUNCE_OFFSET               (144u)
#define key_touch_BUTTON4_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON4_PTR2DEBOUNCE_PARAM_ID             (0xDB040090u)

#define key_touch_BUTTON4_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[4].staticConfig)
#define key_touch_BUTTON4_STATIC_CONFIG_OFFSET              (148u)
#define key_touch_BUTTON4_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON4_STATIC_CONFIG_PARAM_ID            (0x95040094u)

#define key_touch_BUTTON4_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[4].totalNumSns)
#define key_touch_BUTTON4_TOTAL_NUM_SNS_OFFSET              (150u)
#define key_touch_BUTTON4_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON4_TOTAL_NUM_SNS_PARAM_ID            (0x99040096u)

#define key_touch_BUTTON4_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[4].wdgtType)
#define key_touch_BUTTON4_TYPE_OFFSET                       (152u)
#define key_touch_BUTTON4_TYPE_SIZE                         (1u)
#define key_touch_BUTTON4_TYPE_PARAM_ID                     (0x5E040098u)

#define key_touch_BUTTON4_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[4].numCols)
#define key_touch_BUTTON4_NUM_COLS_OFFSET                   (153u)
#define key_touch_BUTTON4_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON4_NUM_COLS_PARAM_ID                 (0x58040099u)

#define key_touch_BUTTON4_PTR2NOISE_ENVLP_VALUE             (key_touch_dsFlash.wdgtArray[4].ptr2NoiseEnvlp)
#define key_touch_BUTTON4_PTR2NOISE_ENVLP_OFFSET            (156u)
#define key_touch_BUTTON4_PTR2NOISE_ENVLP_SIZE              (4u)
#define key_touch_BUTTON4_PTR2NOISE_ENVLP_PARAM_ID          (0xD804009Cu)

#define key_touch_BUTTON5_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[5].ptr2SnsFlash)
#define key_touch_BUTTON5_PTR2SNS_FLASH_OFFSET              (160u)
#define key_touch_BUTTON5_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON5_PTR2SNS_FLASH_PARAM_ID            (0xD70500A0u)

#define key_touch_BUTTON5_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[5].ptr2WdgtRam)
#define key_touch_BUTTON5_PTR2WD_RAM_OFFSET                 (164u)
#define key_touch_BUTTON5_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON5_PTR2WD_RAM_PARAM_ID               (0xD60500A4u)

#define key_touch_BUTTON5_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[5].ptr2SnsRam)
#define key_touch_BUTTON5_PTR2SNS_RAM_OFFSET                (168u)
#define key_touch_BUTTON5_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON5_PTR2SNS_RAM_PARAM_ID              (0xD50500A8u)

#define key_touch_BUTTON5_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[5].ptr2FltrHistory)
#define key_touch_BUTTON5_PTR2FLTR_HISTORY_OFFSET           (172u)
#define key_touch_BUTTON5_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON5_PTR2FLTR_HISTORY_PARAM_ID         (0xD40500ACu)

#define key_touch_BUTTON5_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[5].ptr2DebounceArr)
#define key_touch_BUTTON5_PTR2DEBOUNCE_OFFSET               (176u)
#define key_touch_BUTTON5_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON5_PTR2DEBOUNCE_PARAM_ID             (0xD20500B0u)

#define key_touch_BUTTON5_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[5].staticConfig)
#define key_touch_BUTTON5_STATIC_CONFIG_OFFSET              (180u)
#define key_touch_BUTTON5_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON5_STATIC_CONFIG_PARAM_ID            (0x9C0500B4u)

#define key_touch_BUTTON5_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[5].totalNumSns)
#define key_touch_BUTTON5_TOTAL_NUM_SNS_OFFSET              (182u)
#define key_touch_BUTTON5_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON5_TOTAL_NUM_SNS_PARAM_ID            (0x900500B6u)

#define key_touch_BUTTON5_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[5].wdgtType)
#define key_touch_BUTTON5_TYPE_OFFSET                       (184u)
#define key_touch_BUTTON5_TYPE_SIZE                         (1u)
#define key_touch_BUTTON5_TYPE_PARAM_ID                     (0x570500B8u)

#define key_touch_BUTTON5_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[5].numCols)
#define key_touch_BUTTON5_NUM_COLS_OFFSET                   (185u)
#define key_touch_BUTTON5_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON5_NUM_COLS_PARAM_ID                 (0x510500B9u)

#define key_touch_BUTTON5_PTR2NOISE_ENVLP_VALUE             (key_touch_dsFlash.wdgtArray[5].ptr2NoiseEnvlp)
#define key_touch_BUTTON5_PTR2NOISE_ENVLP_OFFSET            (188u)
#define key_touch_BUTTON5_PTR2NOISE_ENVLP_SIZE              (4u)
#define key_touch_BUTTON5_PTR2NOISE_ENVLP_PARAM_ID          (0xD10500BCu)

#define key_touch_BUTTON6_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[6].ptr2SnsFlash)
#define key_touch_BUTTON6_PTR2SNS_FLASH_OFFSET              (192u)
#define key_touch_BUTTON6_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON6_PTR2SNS_FLASH_PARAM_ID            (0xD50600C0u)

#define key_touch_BUTTON6_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[6].ptr2WdgtRam)
#define key_touch_BUTTON6_PTR2WD_RAM_OFFSET                 (196u)
#define key_touch_BUTTON6_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON6_PTR2WD_RAM_PARAM_ID               (0xD40600C4u)

#define key_touch_BUTTON6_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[6].ptr2SnsRam)
#define key_touch_BUTTON6_PTR2SNS_RAM_OFFSET                (200u)
#define key_touch_BUTTON6_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON6_PTR2SNS_RAM_PARAM_ID              (0xD70600C8u)

#define key_touch_BUTTON6_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[6].ptr2FltrHistory)
#define key_touch_BUTTON6_PTR2FLTR_HISTORY_OFFSET           (204u)
#define key_touch_BUTTON6_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON6_PTR2FLTR_HISTORY_PARAM_ID         (0xD60600CCu)

#define key_touch_BUTTON6_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[6].ptr2DebounceArr)
#define key_touch_BUTTON6_PTR2DEBOUNCE_OFFSET               (208u)
#define key_touch_BUTTON6_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON6_PTR2DEBOUNCE_PARAM_ID             (0xD00600D0u)

#define key_touch_BUTTON6_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[6].staticConfig)
#define key_touch_BUTTON6_STATIC_CONFIG_OFFSET              (212u)
#define key_touch_BUTTON6_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON6_STATIC_CONFIG_PARAM_ID            (0x9E0600D4u)

#define key_touch_BUTTON6_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[6].totalNumSns)
#define key_touch_BUTTON6_TOTAL_NUM_SNS_OFFSET              (214u)
#define key_touch_BUTTON6_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON6_TOTAL_NUM_SNS_PARAM_ID            (0x920600D6u)

#define key_touch_BUTTON6_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[6].wdgtType)
#define key_touch_BUTTON6_TYPE_OFFSET                       (216u)
#define key_touch_BUTTON6_TYPE_SIZE                         (1u)
#define key_touch_BUTTON6_TYPE_PARAM_ID                     (0x550600D8u)

#define key_touch_BUTTON6_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[6].numCols)
#define key_touch_BUTTON6_NUM_COLS_OFFSET                   (217u)
#define key_touch_BUTTON6_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON6_NUM_COLS_PARAM_ID                 (0x530600D9u)

#define key_touch_BUTTON6_PTR2NOISE_ENVLP_VALUE             (key_touch_dsFlash.wdgtArray[6].ptr2NoiseEnvlp)
#define key_touch_BUTTON6_PTR2NOISE_ENVLP_OFFSET            (220u)
#define key_touch_BUTTON6_PTR2NOISE_ENVLP_SIZE              (4u)
#define key_touch_BUTTON6_PTR2NOISE_ENVLP_PARAM_ID          (0xD30600DCu)

#define key_touch_BUTTON7_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[7].ptr2SnsFlash)
#define key_touch_BUTTON7_PTR2SNS_FLASH_OFFSET              (224u)
#define key_touch_BUTTON7_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON7_PTR2SNS_FLASH_PARAM_ID            (0xDC0700E0u)

#define key_touch_BUTTON7_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[7].ptr2WdgtRam)
#define key_touch_BUTTON7_PTR2WD_RAM_OFFSET                 (228u)
#define key_touch_BUTTON7_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON7_PTR2WD_RAM_PARAM_ID               (0xDD0700E4u)

#define key_touch_BUTTON7_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[7].ptr2SnsRam)
#define key_touch_BUTTON7_PTR2SNS_RAM_OFFSET                (232u)
#define key_touch_BUTTON7_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON7_PTR2SNS_RAM_PARAM_ID              (0xDE0700E8u)

#define key_touch_BUTTON7_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[7].ptr2FltrHistory)
#define key_touch_BUTTON7_PTR2FLTR_HISTORY_OFFSET           (236u)
#define key_touch_BUTTON7_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON7_PTR2FLTR_HISTORY_PARAM_ID         (0xDF0700ECu)

#define key_touch_BUTTON7_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[7].ptr2DebounceArr)
#define key_touch_BUTTON7_PTR2DEBOUNCE_OFFSET               (240u)
#define key_touch_BUTTON7_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON7_PTR2DEBOUNCE_PARAM_ID             (0xD90700F0u)

#define key_touch_BUTTON7_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[7].staticConfig)
#define key_touch_BUTTON7_STATIC_CONFIG_OFFSET              (244u)
#define key_touch_BUTTON7_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON7_STATIC_CONFIG_PARAM_ID            (0x970700F4u)

#define key_touch_BUTTON7_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[7].totalNumSns)
#define key_touch_BUTTON7_TOTAL_NUM_SNS_OFFSET              (246u)
#define key_touch_BUTTON7_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON7_TOTAL_NUM_SNS_PARAM_ID            (0x9B0700F6u)

#define key_touch_BUTTON7_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[7].wdgtType)
#define key_touch_BUTTON7_TYPE_OFFSET                       (248u)
#define key_touch_BUTTON7_TYPE_SIZE                         (1u)
#define key_touch_BUTTON7_TYPE_PARAM_ID                     (0x5C0700F8u)

#define key_touch_BUTTON7_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[7].numCols)
#define key_touch_BUTTON7_NUM_COLS_OFFSET                   (249u)
#define key_touch_BUTTON7_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON7_NUM_COLS_PARAM_ID                 (0x5A0700F9u)

#define key_touch_BUTTON7_PTR2NOISE_ENVLP_VALUE             (key_touch_dsFlash.wdgtArray[7].ptr2NoiseEnvlp)
#define key_touch_BUTTON7_PTR2NOISE_ENVLP_OFFSET            (252u)
#define key_touch_BUTTON7_PTR2NOISE_ENVLP_SIZE              (4u)
#define key_touch_BUTTON7_PTR2NOISE_ENVLP_PARAM_ID          (0xDA0700FCu)

#define key_touch_BUTTON8_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[8].ptr2SnsFlash)
#define key_touch_BUTTON8_PTR2SNS_FLASH_OFFSET              (256u)
#define key_touch_BUTTON8_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON8_PTR2SNS_FLASH_PARAM_ID            (0xDB080100u)

#define key_touch_BUTTON8_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[8].ptr2WdgtRam)
#define key_touch_BUTTON8_PTR2WD_RAM_OFFSET                 (260u)
#define key_touch_BUTTON8_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON8_PTR2WD_RAM_PARAM_ID               (0xDA080104u)

#define key_touch_BUTTON8_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[8].ptr2SnsRam)
#define key_touch_BUTTON8_PTR2SNS_RAM_OFFSET                (264u)
#define key_touch_BUTTON8_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON8_PTR2SNS_RAM_PARAM_ID              (0xD9080108u)

#define key_touch_BUTTON8_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[8].ptr2FltrHistory)
#define key_touch_BUTTON8_PTR2FLTR_HISTORY_OFFSET           (268u)
#define key_touch_BUTTON8_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON8_PTR2FLTR_HISTORY_PARAM_ID         (0xD808010Cu)

#define key_touch_BUTTON8_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[8].ptr2DebounceArr)
#define key_touch_BUTTON8_PTR2DEBOUNCE_OFFSET               (272u)
#define key_touch_BUTTON8_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON8_PTR2DEBOUNCE_PARAM_ID             (0xDE080110u)

#define key_touch_BUTTON8_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[8].staticConfig)
#define key_touch_BUTTON8_STATIC_CONFIG_OFFSET              (276u)
#define key_touch_BUTTON8_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON8_STATIC_CONFIG_PARAM_ID            (0x90080114u)

#define key_touch_BUTTON8_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[8].totalNumSns)
#define key_touch_BUTTON8_TOTAL_NUM_SNS_OFFSET              (278u)
#define key_touch_BUTTON8_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON8_TOTAL_NUM_SNS_PARAM_ID            (0x9C080116u)

#define key_touch_BUTTON8_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[8].wdgtType)
#define key_touch_BUTTON8_TYPE_OFFSET                       (280u)
#define key_touch_BUTTON8_TYPE_SIZE                         (1u)
#define key_touch_BUTTON8_TYPE_PARAM_ID                     (0x5B080118u)

#define key_touch_BUTTON8_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[8].numCols)
#define key_touch_BUTTON8_NUM_COLS_OFFSET                   (281u)
#define key_touch_BUTTON8_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON8_NUM_COLS_PARAM_ID                 (0x5D080119u)

#define key_touch_BUTTON8_PTR2NOISE_ENVLP_VALUE             (key_touch_dsFlash.wdgtArray[8].ptr2NoiseEnvlp)
#define key_touch_BUTTON8_PTR2NOISE_ENVLP_OFFSET            (284u)
#define key_touch_BUTTON8_PTR2NOISE_ENVLP_SIZE              (4u)
#define key_touch_BUTTON8_PTR2NOISE_ENVLP_PARAM_ID          (0xDD08011Cu)

#define key_touch_BUTTON9_PTR2SNS_FLASH_VALUE               (key_touch_dsFlash.wdgtArray[9].ptr2SnsFlash)
#define key_touch_BUTTON9_PTR2SNS_FLASH_OFFSET              (288u)
#define key_touch_BUTTON9_PTR2SNS_FLASH_SIZE                (4u)
#define key_touch_BUTTON9_PTR2SNS_FLASH_PARAM_ID            (0xD2090120u)

#define key_touch_BUTTON9_PTR2WD_RAM_VALUE                  (key_touch_dsFlash.wdgtArray[9].ptr2WdgtRam)
#define key_touch_BUTTON9_PTR2WD_RAM_OFFSET                 (292u)
#define key_touch_BUTTON9_PTR2WD_RAM_SIZE                   (4u)
#define key_touch_BUTTON9_PTR2WD_RAM_PARAM_ID               (0xD3090124u)

#define key_touch_BUTTON9_PTR2SNS_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[9].ptr2SnsRam)
#define key_touch_BUTTON9_PTR2SNS_RAM_OFFSET                (296u)
#define key_touch_BUTTON9_PTR2SNS_RAM_SIZE                  (4u)
#define key_touch_BUTTON9_PTR2SNS_RAM_PARAM_ID              (0xD0090128u)

#define key_touch_BUTTON9_PTR2FLTR_HISTORY_VALUE            (key_touch_dsFlash.wdgtArray[9].ptr2FltrHistory)
#define key_touch_BUTTON9_PTR2FLTR_HISTORY_OFFSET           (300u)
#define key_touch_BUTTON9_PTR2FLTR_HISTORY_SIZE             (4u)
#define key_touch_BUTTON9_PTR2FLTR_HISTORY_PARAM_ID         (0xD109012Cu)

#define key_touch_BUTTON9_PTR2DEBOUNCE_VALUE                (key_touch_dsFlash.wdgtArray[9].ptr2DebounceArr)
#define key_touch_BUTTON9_PTR2DEBOUNCE_OFFSET               (304u)
#define key_touch_BUTTON9_PTR2DEBOUNCE_SIZE                 (4u)
#define key_touch_BUTTON9_PTR2DEBOUNCE_PARAM_ID             (0xD7090130u)

#define key_touch_BUTTON9_STATIC_CONFIG_VALUE               (key_touch_dsFlash.wdgtArray[9].staticConfig)
#define key_touch_BUTTON9_STATIC_CONFIG_OFFSET              (308u)
#define key_touch_BUTTON9_STATIC_CONFIG_SIZE                (2u)
#define key_touch_BUTTON9_STATIC_CONFIG_PARAM_ID            (0x99090134u)

#define key_touch_BUTTON9_TOTAL_NUM_SNS_VALUE               (key_touch_dsFlash.wdgtArray[9].totalNumSns)
#define key_touch_BUTTON9_TOTAL_NUM_SNS_OFFSET              (310u)
#define key_touch_BUTTON9_TOTAL_NUM_SNS_SIZE                (2u)
#define key_touch_BUTTON9_TOTAL_NUM_SNS_PARAM_ID            (0x95090136u)

#define key_touch_BUTTON9_TYPE_VALUE                        (key_touch_dsFlash.wdgtArray[9].wdgtType)
#define key_touch_BUTTON9_TYPE_OFFSET                       (312u)
#define key_touch_BUTTON9_TYPE_SIZE                         (1u)
#define key_touch_BUTTON9_TYPE_PARAM_ID                     (0x52090138u)

#define key_touch_BUTTON9_NUM_COLS_VALUE                    (key_touch_dsFlash.wdgtArray[9].numCols)
#define key_touch_BUTTON9_NUM_COLS_OFFSET                   (313u)
#define key_touch_BUTTON9_NUM_COLS_SIZE                     (1u)
#define key_touch_BUTTON9_NUM_COLS_PARAM_ID                 (0x54090139u)

#define key_touch_BUTTON9_PTR2NOISE_ENVLP_VALUE             (key_touch_dsFlash.wdgtArray[9].ptr2NoiseEnvlp)
#define key_touch_BUTTON9_PTR2NOISE_ENVLP_OFFSET            (316u)
#define key_touch_BUTTON9_PTR2NOISE_ENVLP_SIZE              (4u)
#define key_touch_BUTTON9_PTR2NOISE_ENVLP_PARAM_ID          (0xD409013Cu)

#define key_touch_BUTTON10_PTR2SNS_FLASH_VALUE              (key_touch_dsFlash.wdgtArray[10].ptr2SnsFlash)
#define key_touch_BUTTON10_PTR2SNS_FLASH_OFFSET             (320u)
#define key_touch_BUTTON10_PTR2SNS_FLASH_SIZE               (4u)
#define key_touch_BUTTON10_PTR2SNS_FLASH_PARAM_ID           (0xD00A0140u)

#define key_touch_BUTTON10_PTR2WD_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[10].ptr2WdgtRam)
#define key_touch_BUTTON10_PTR2WD_RAM_OFFSET                (324u)
#define key_touch_BUTTON10_PTR2WD_RAM_SIZE                  (4u)
#define key_touch_BUTTON10_PTR2WD_RAM_PARAM_ID              (0xD10A0144u)

#define key_touch_BUTTON10_PTR2SNS_RAM_VALUE                (key_touch_dsFlash.wdgtArray[10].ptr2SnsRam)
#define key_touch_BUTTON10_PTR2SNS_RAM_OFFSET               (328u)
#define key_touch_BUTTON10_PTR2SNS_RAM_SIZE                 (4u)
#define key_touch_BUTTON10_PTR2SNS_RAM_PARAM_ID             (0xD20A0148u)

#define key_touch_BUTTON10_PTR2FLTR_HISTORY_VALUE           (key_touch_dsFlash.wdgtArray[10].ptr2FltrHistory)
#define key_touch_BUTTON10_PTR2FLTR_HISTORY_OFFSET          (332u)
#define key_touch_BUTTON10_PTR2FLTR_HISTORY_SIZE            (4u)
#define key_touch_BUTTON10_PTR2FLTR_HISTORY_PARAM_ID        (0xD30A014Cu)

#define key_touch_BUTTON10_PTR2DEBOUNCE_VALUE               (key_touch_dsFlash.wdgtArray[10].ptr2DebounceArr)
#define key_touch_BUTTON10_PTR2DEBOUNCE_OFFSET              (336u)
#define key_touch_BUTTON10_PTR2DEBOUNCE_SIZE                (4u)
#define key_touch_BUTTON10_PTR2DEBOUNCE_PARAM_ID            (0xD50A0150u)

#define key_touch_BUTTON10_STATIC_CONFIG_VALUE              (key_touch_dsFlash.wdgtArray[10].staticConfig)
#define key_touch_BUTTON10_STATIC_CONFIG_OFFSET             (340u)
#define key_touch_BUTTON10_STATIC_CONFIG_SIZE               (2u)
#define key_touch_BUTTON10_STATIC_CONFIG_PARAM_ID           (0x9B0A0154u)

#define key_touch_BUTTON10_TOTAL_NUM_SNS_VALUE              (key_touch_dsFlash.wdgtArray[10].totalNumSns)
#define key_touch_BUTTON10_TOTAL_NUM_SNS_OFFSET             (342u)
#define key_touch_BUTTON10_TOTAL_NUM_SNS_SIZE               (2u)
#define key_touch_BUTTON10_TOTAL_NUM_SNS_PARAM_ID           (0x970A0156u)

#define key_touch_BUTTON10_TYPE_VALUE                       (key_touch_dsFlash.wdgtArray[10].wdgtType)
#define key_touch_BUTTON10_TYPE_OFFSET                      (344u)
#define key_touch_BUTTON10_TYPE_SIZE                        (1u)
#define key_touch_BUTTON10_TYPE_PARAM_ID                    (0x500A0158u)

#define key_touch_BUTTON10_NUM_COLS_VALUE                   (key_touch_dsFlash.wdgtArray[10].numCols)
#define key_touch_BUTTON10_NUM_COLS_OFFSET                  (345u)
#define key_touch_BUTTON10_NUM_COLS_SIZE                    (1u)
#define key_touch_BUTTON10_NUM_COLS_PARAM_ID                (0x560A0159u)

#define key_touch_BUTTON10_PTR2NOISE_ENVLP_VALUE            (key_touch_dsFlash.wdgtArray[10].ptr2NoiseEnvlp)
#define key_touch_BUTTON10_PTR2NOISE_ENVLP_OFFSET           (348u)
#define key_touch_BUTTON10_PTR2NOISE_ENVLP_SIZE             (4u)
#define key_touch_BUTTON10_PTR2NOISE_ENVLP_PARAM_ID         (0xD60A015Cu)

#define key_touch_BUTTON11_PTR2SNS_FLASH_VALUE              (key_touch_dsFlash.wdgtArray[11].ptr2SnsFlash)
#define key_touch_BUTTON11_PTR2SNS_FLASH_OFFSET             (352u)
#define key_touch_BUTTON11_PTR2SNS_FLASH_SIZE               (4u)
#define key_touch_BUTTON11_PTR2SNS_FLASH_PARAM_ID           (0xD90B0160u)

#define key_touch_BUTTON11_PTR2WD_RAM_VALUE                 (key_touch_dsFlash.wdgtArray[11].ptr2WdgtRam)
#define key_touch_BUTTON11_PTR2WD_RAM_OFFSET                (356u)
#define key_touch_BUTTON11_PTR2WD_RAM_SIZE                  (4u)
#define key_touch_BUTTON11_PTR2WD_RAM_PARAM_ID              (0xD80B0164u)

#define key_touch_BUTTON11_PTR2SNS_RAM_VALUE                (key_touch_dsFlash.wdgtArray[11].ptr2SnsRam)
#define key_touch_BUTTON11_PTR2SNS_RAM_OFFSET               (360u)
#define key_touch_BUTTON11_PTR2SNS_RAM_SIZE                 (4u)
#define key_touch_BUTTON11_PTR2SNS_RAM_PARAM_ID             (0xDB0B0168u)

#define key_touch_BUTTON11_PTR2FLTR_HISTORY_VALUE           (key_touch_dsFlash.wdgtArray[11].ptr2FltrHistory)
#define key_touch_BUTTON11_PTR2FLTR_HISTORY_OFFSET          (364u)
#define key_touch_BUTTON11_PTR2FLTR_HISTORY_SIZE            (4u)
#define key_touch_BUTTON11_PTR2FLTR_HISTORY_PARAM_ID        (0xDA0B016Cu)

#define key_touch_BUTTON11_PTR2DEBOUNCE_VALUE               (key_touch_dsFlash.wdgtArray[11].ptr2DebounceArr)
#define key_touch_BUTTON11_PTR2DEBOUNCE_OFFSET              (368u)
#define key_touch_BUTTON11_PTR2DEBOUNCE_SIZE                (4u)
#define key_touch_BUTTON11_PTR2DEBOUNCE_PARAM_ID            (0xDC0B0170u)

#define key_touch_BUTTON11_STATIC_CONFIG_VALUE              (key_touch_dsFlash.wdgtArray[11].staticConfig)
#define key_touch_BUTTON11_STATIC_CONFIG_OFFSET             (372u)
#define key_touch_BUTTON11_STATIC_CONFIG_SIZE               (2u)
#define key_touch_BUTTON11_STATIC_CONFIG_PARAM_ID           (0x920B0174u)

#define key_touch_BUTTON11_TOTAL_NUM_SNS_VALUE              (key_touch_dsFlash.wdgtArray[11].totalNumSns)
#define key_touch_BUTTON11_TOTAL_NUM_SNS_OFFSET             (374u)
#define key_touch_BUTTON11_TOTAL_NUM_SNS_SIZE               (2u)
#define key_touch_BUTTON11_TOTAL_NUM_SNS_PARAM_ID           (0x9E0B0176u)

#define key_touch_BUTTON11_TYPE_VALUE                       (key_touch_dsFlash.wdgtArray[11].wdgtType)
#define key_touch_BUTTON11_TYPE_OFFSET                      (376u)
#define key_touch_BUTTON11_TYPE_SIZE                        (1u)
#define key_touch_BUTTON11_TYPE_PARAM_ID                    (0x590B0178u)

#define key_touch_BUTTON11_NUM_COLS_VALUE                   (key_touch_dsFlash.wdgtArray[11].numCols)
#define key_touch_BUTTON11_NUM_COLS_OFFSET                  (377u)
#define key_touch_BUTTON11_NUM_COLS_SIZE                    (1u)
#define key_touch_BUTTON11_NUM_COLS_PARAM_ID                (0x5F0B0179u)

#define key_touch_BUTTON11_PTR2NOISE_ENVLP_VALUE            (key_touch_dsFlash.wdgtArray[11].ptr2NoiseEnvlp)
#define key_touch_BUTTON11_PTR2NOISE_ENVLP_OFFSET           (380u)
#define key_touch_BUTTON11_PTR2NOISE_ENVLP_SIZE             (4u)
#define key_touch_BUTTON11_PTR2NOISE_ENVLP_PARAM_ID         (0xDF0B017Cu)


#endif /* End CY_CAPSENSE_key_touch_REGISTER_MAP_H */

/* [] END OF FILE */
