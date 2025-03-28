/*
 * Renesas SCP/MCP Software
 * Copyright (c) 2020-2021, Renesas Electronics Corporation. All rights
 * reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef RCAR4_SCMI_ID_H
#define RCAR4_SCMI_ID_H
/* Fatih: temp indexes erstmal einfach nur von rcar4 kopiert*/
/* SCMI PowerDomain Domain indexes */
enum rcar4_scmi_pd_domain_id {
    PD_RCAR4_CLUS0CORE0 = 0,
    PD_RCAR4_CLUS0CORE1,
    PD_RCAR4_CLUS0CORE2,
    PD_RCAR4_CLUS0CORE3,
    PD_RCAR4_CLUS1CORE0,
    PD_RCAR4_CLUS1CORE1,
    PD_RCAR4_CLUS1CORE2,
    PD_RCAR4_CLUS1CORE3,
    PD_RCAR4_CLUSTER0,
    PD_RCAR4_CLUSTER1,
    PD_RCAR4_A3IR,
    PD_RCAR4_3DGE,
    PD_RCAR4_3DGD,
    PD_RCAR4_3DGC,
    PD_RCAR4_3DGB,
    PD_RCAR4_3DGA,
    PD_RCAR4_A2VC1,
    PD_RCAR4_A3VC,
    PD_RCAR4_CR7,
    PD_RCAR4_A3VP,
    PD_RCAR4_PMIC_DDR_BKUP,
    PD_RCAR4_ALWAYS_ON,
    PD_RCAR4_COUNT,
};

/* SCMI Clock indexes */
enum rcar4_scmi_clock_id {
    CLOCK_RCAR4_ZTR,
    CLOCK_RCAR4_ZTRD2,
    CLOCK_RCAR4_ZT,
    CLOCK_RCAR4_ZX,
    CLOCK_RCAR4_S0D1,
    CLOCK_RCAR4_S0D2,
    CLOCK_RCAR4_S0D3,
    CLOCK_RCAR4_S0D4,
    CLOCK_RCAR4_S0D6,
    CLOCK_RCAR4_S0D8,
    CLOCK_RCAR4_S0D12,
    CLOCK_RCAR4_S1D1,
    CLOCK_RCAR4_S1D2,
    CLOCK_RCAR4_S1D4,
    CLOCK_RCAR4_S2D1,
    CLOCK_RCAR4_S2D2,
    CLOCK_RCAR4_S2D4,
    CLOCK_RCAR4_S3D1,
    CLOCK_RCAR4_S3D2,
    CLOCK_RCAR4_S3D4,
    CLOCK_RCAR4_SD0,
    CLOCK_RCAR4_SD1,
    CLOCK_RCAR4_SD2,
    CLOCK_RCAR4_SD3,
    CLOCK_RCAR4_CL,
    CLOCK_RCAR4_CR,
    CLOCK_RCAR4_CP,
    CLOCK_RCAR4_CPEX,
    CLOCK_RCAR4_CANFD,
    CLOCK_RCAR4_CSI0,
    CLOCK_RCAR4_MSO,
    CLOCK_RCAR4_HDMI,
    CLOCK_RCAR4_OSC,
    CLOCK_RCAR4_R,
    CLOCK_RCAR4_S0,
    CLOCK_RCAR4_S1,
    CLOCK_RCAR4_S2,
    CLOCK_RCAR4_S3,
    CLOCK_RCAR4_SDSRC,
    CLOCK_RCAR4_RINT,
    CLOCK_RCAR4_FDP1_1,
    CLOCK_RCAR4_FDP1_0,
    CLOCK_RCAR4_SCIF5,
    CLOCK_RCAR4_SCIF4,
    CLOCK_RCAR4_SCIF3,
    CLOCK_RCAR4_SCIF1,
    CLOCK_RCAR4_SCIF0,
    CLOCK_RCAR4_MSIOF3,
    CLOCK_RCAR4_MSIOF2,
    CLOCK_RCAR4_MSIOF1,
    CLOCK_RCAR4_MSIOF0,
    CLOCK_RCAR4_SYS_DMAC2,
    CLOCK_RCAR4_SYS_DMAC1,
    CLOCK_RCAR4_SYS_DMAC0,
    CLOCK_RCAR4_SCEG_PUB,
    CLOCK_RCAR4_CMT3,
    CLOCK_RCAR4_CMT2,
    CLOCK_RCAR4_CMT1,
    CLOCK_RCAR4_CMT0,
    CLOCK_RCAR4_TPU0,
    CLOCK_RCAR4_SCIF2,
    CLOCK_RCAR4_SDIF3,
    CLOCK_RCAR4_SDIF2,
    CLOCK_RCAR4_SDIF1,
    CLOCK_RCAR4_SDIF0,
    CLOCK_RCAR4_PCIE1,
    CLOCK_RCAR4_PCIE0,
    CLOCK_RCAR4_USB_DMAC30,
    CLOCK_RCAR4_USB3_IF0,
    CLOCK_RCAR4_USB_DMAC31,
    CLOCK_RCAR4_USB_DMAC0,
    CLOCK_RCAR4_USB_DMAC1,
    CLOCK_RCAR4_RWDT,
    CLOCK_RCAR4_INTC_EX,
    CLOCK_RCAR4_INTC_AP,
    CLOCK_RCAR4_AUDMAC1,
    CLOCK_RCAR4_AUDMAC0,
    CLOCK_RCAR4_DRIF31,
    CLOCK_RCAR4_DRIF30,
    CLOCK_RCAR4_DRIF21,
    CLOCK_RCAR4_DRIF20,
    CLOCK_RCAR4_DRIF11,
    CLOCK_RCAR4_DRIF10,
    CLOCK_RCAR4_DRIF01,
    CLOCK_RCAR4_DRIF00,
    CLOCK_RCAR4_HSCIF4,
    CLOCK_RCAR4_HSCIF3,
    CLOCK_RCAR4_HSCIF2,
    CLOCK_RCAR4_HSCIF1,
    CLOCK_RCAR4_HSCIF0,
    CLOCK_RCAR4_THERMAL,
    CLOCK_RCAR4_PWM,
    CLOCK_RCAR4_FCPVD2,
    CLOCK_RCAR4_FCPVD1,
    CLOCK_RCAR4_FCPVD0,
    CLOCK_RCAR4_FCPVB1,
    CLOCK_RCAR4_FCPVB0,
    CLOCK_RCAR4_FCPVI1,
    CLOCK_RCAR4_FCPVI0,
    CLOCK_RCAR4_FCPF1,
    CLOCK_RCAR4_FCPF0,
    CLOCK_RCAR4_FCPCS,
    CLOCK_RCAR4_VSPD2,
    CLOCK_RCAR4_VSPD1,
    CLOCK_RCAR4_VSPD0,
    CLOCK_RCAR4_VSPBC,
    CLOCK_RCAR4_VSPBD,
    CLOCK_RCAR4_VSPI1,
    CLOCK_RCAR4_VSPI0,
    CLOCK_RCAR4_EHCI3,
    CLOCK_RCAR4_EHCI2,
    CLOCK_RCAR4_EHCI1,
    CLOCK_RCAR4_EHCI0,
    CLOCK_RCAR4_HSUSB,
    CLOCK_RCAR4_HSUSB3,
    CLOCK_RCAR4_CMM3,
    CLOCK_RCAR4_CMM2,
    CLOCK_RCAR4_CMM1,
    CLOCK_RCAR4_CMM0,
    CLOCK_RCAR4_CSI20,
    CLOCK_RCAR4_CSI41,
    CLOCK_RCAR4_CSI40,
    CLOCK_RCAR4_DU3,
    CLOCK_RCAR4_DU2,
    CLOCK_RCAR4_DU1,
    CLOCK_RCAR4_DU0,
    CLOCK_RCAR4_LVDS,
    CLOCK_RCAR4_HDMI1,
    CLOCK_RCAR4_HDMI0,
    CLOCK_RCAR4_VIN7,
    CLOCK_RCAR4_VIN6,
    CLOCK_RCAR4_VIN5,
    CLOCK_RCAR4_VIN4,
    CLOCK_RCAR4_VIN3,
    CLOCK_RCAR4_VIN2,
    CLOCK_RCAR4_VIN1,
    CLOCK_RCAR4_VIN0,
    CLOCK_RCAR4_ETHERAVB,
    CLOCK_RCAR4_SATA0,
    CLOCK_RCAR4_IMR3,
    CLOCK_RCAR4_IMR2,
    CLOCK_RCAR4_IMR1,
    CLOCK_RCAR4_IMR0,
    CLOCK_RCAR4_GPIO7,
    CLOCK_RCAR4_GPIO6,
    CLOCK_RCAR4_GPIO5,
    CLOCK_RCAR4_GPIO4,
    CLOCK_RCAR4_GPIO3,
    CLOCK_RCAR4_GPIO2,
    CLOCK_RCAR4_GPIO1,
    CLOCK_RCAR4_GPIO0,
    CLOCK_RCAR4_CAN_FD,
    CLOCK_RCAR4_CAN_IF1,
    CLOCK_RCAR4_CAN_IF0,
    CLOCK_RCAR4_I2C6,
    CLOCK_RCAR4_I2C5,
    CLOCK_RCAR4_I2C_DVFS,
    CLOCK_RCAR4_I2C4,
    CLOCK_RCAR4_I2C3,
    CLOCK_RCAR4_I2C2,
    CLOCK_RCAR4_I2C1,
    CLOCK_RCAR4_I2C0,
    CLOCK_RCAR4_SSI_ALL,
    CLOCK_RCAR4_SSI9,
    CLOCK_RCAR4_SSI8,
    CLOCK_RCAR4_SSI7,
    CLOCK_RCAR4_SSI6,
    CLOCK_RCAR4_SSI5,
    CLOCK_RCAR4_SSI4,
    CLOCK_RCAR4_SSI3,
    CLOCK_RCAR4_SSI2,
    CLOCK_RCAR4_SSI1,
    CLOCK_RCAR4_SSI0,
    CLOCK_RCAR4_SCU_ALL,
    CLOCK_RCAR4_SCU_DVC1,
    CLOCK_RCAR4_SCU_DVC0,
    CLOCK_RCAR4_SCU_CTU0_MIX1,
    CLOCK_RCAR4_SCU_CTU0_MIX0,
    CLOCK_RCAR4_SCU_SRC9,
    CLOCK_RCAR4_SCU_SRC8,
    CLOCK_RCAR4_SCU_SRC7,
    CLOCK_RCAR4_SCU_SRC6,
    CLOCK_RCAR4_SCU_SRC5,
    CLOCK_RCAR4_SCU_SRC4,
    CLOCK_RCAR4_SCU_SRC3,
    CLOCK_RCAR4_SCU_SRC2,
    CLOCK_RCAR4_SCU_SRC1,
    CLOCK_RCAR4_SCU_SRC0,
    CLOCK_RCAR4_X12_CLK,
    CLOCK_RCAR4_X21_CLK,
    CLOCK_RCAR4_X22_CLK,
    CLOCK_RCAR4_X23_CLK,
    CLOCK_RCAR4_AUDIO_CLKOUT,
    CLOCK_RCAR4_AUDIO_CLK_A,
    CLOCK_RCAR4_AUDIO_CLK_C,
    CLOCK_RCAR4_CAN_CLK,
    CLOCK_RCAR4_PCIE_BUS_CLK,
    CLOCK_RCAR4_SCIF_CLK,
    CLOCK_RCAR4_USB3S0_CLK,
    CLOCK_RCAR4_USB_EXTAL_CLK,
    CLOCK_RCAR4_COUNT,
};

/* SCMI Sensor indexes */
enum rcar4_scmi_sensor_id {
    SENSOR_RCAR4_COUNT,
};

/* SCMI Reset indexes */
enum rcar4_scmi_reset_id {
    RESET_RCAR4_FDP1_1,
    RESET_RCAR4_FDP1_0,
    RESET_RCAR4_SCIF5,
    RESET_RCAR4_SCIF4,
    RESET_RCAR4_SCIF3,
    RESET_RCAR4_SCIF1,
    RESET_RCAR4_SCIF0,
    RESET_RCAR4_MSIOF3,
    RESET_RCAR4_MSIOF2,
    RESET_RCAR4_MSIOF1,
    RESET_RCAR4_MSIOF0,
    RESET_RCAR4_SYS_DMAC2,
    RESET_RCAR4_SYS_DMAC1,
    RESET_RCAR4_SYS_DMAC0,
    RESET_RCAR4_SCEG_PUB,
    RESET_RCAR4_CMT3,
    RESET_RCAR4_CMT2,
    RESET_RCAR4_CMT1,
    RESET_RCAR4_CMT0,
    RESET_RCAR4_TPU0,
    RESET_RCAR4_SCIF2,
    RESET_RCAR4_SDIF3,
    RESET_RCAR4_SDIF2,
    RESET_RCAR4_SDIF1,
    RESET_RCAR4_SDIF0,
    RESET_RCAR4_PCIE1,
    RESET_RCAR4_PCIE0,
    RESET_RCAR4_USB_DMAC30,
    RESET_RCAR4_USB3_IF0,
    RESET_RCAR4_USB_DMAC31,
    RESET_RCAR4_USB_DMAC0,
    RESET_RCAR4_USB_DMAC1,
    RESET_RCAR4_RWDT,
    RESET_RCAR4_INTC_EX,
    RESET_RCAR4_INTC_AP,
    RESET_RCAR4_AUDMAC1,
    RESET_RCAR4_AUDMAC0,
    RESET_RCAR4_DRIF31,
    RESET_RCAR4_DRIF30,
    RESET_RCAR4_DRIF21,
    RESET_RCAR4_DRIF20,
    RESET_RCAR4_DRIF11,
    RESET_RCAR4_DRIF10,
    RESET_RCAR4_DRIF01,
    RESET_RCAR4_DRIF00,
    RESET_RCAR4_HSCIF4,
    RESET_RCAR4_HSCIF3,
    RESET_RCAR4_HSCIF2,
    RESET_RCAR4_HSCIF1,
    RESET_RCAR4_HSCIF0,
    RESET_RCAR4_THERMAL,
    RESET_RCAR4_PWM,
    RESET_RCAR4_FCPVD2,
    RESET_RCAR4_FCPVD1,
    RESET_RCAR4_FCPVD0,
    RESET_RCAR4_FCPVB1,
    RESET_RCAR4_FCPVB0,
    RESET_RCAR4_FCPVI1,
    RESET_RCAR4_FCPVI0,
    RESET_RCAR4_FCPF1,
    RESET_RCAR4_FCPF0,
    RESET_RCAR4_FCPCS,
    RESET_RCAR4_VSPD2,
    RESET_RCAR4_VSPD1,
    RESET_RCAR4_VSPD0,
    RESET_RCAR4_VSPBC,
    RESET_RCAR4_VSPBD,
    RESET_RCAR4_VSPI1,
    RESET_RCAR4_VSPI0,
    RESET_RCAR4_EHCI3,
    RESET_RCAR4_EHCI2,
    RESET_RCAR4_EHCI1,
    RESET_RCAR4_EHCI0,
    RESET_RCAR4_HSUSB,
    RESET_RCAR4_HSUSB3,
    RESET_RCAR4_CMM3,
    RESET_RCAR4_CMM2,
    RESET_RCAR4_CMM1,
    RESET_RCAR4_CMM0,
    RESET_RCAR4_CSI20,
    RESET_RCAR4_CSI41,
    RESET_RCAR4_CSI40,
    RESET_RCAR4_DU3,
    RESET_RCAR4_DU2,
    RESET_RCAR4_DU1,
    RESET_RCAR4_DU0,
    RESET_RCAR4_LVDS,
    RESET_RCAR4_HDMI1,
    RESET_RCAR4_HDMI0,
    RESET_RCAR4_VIN7,
    RESET_RCAR4_VIN6,
    RESET_RCAR4_VIN5,
    RESET_RCAR4_VIN4,
    RESET_RCAR4_VIN3,
    RESET_RCAR4_VIN2,
    RESET_RCAR4_VIN1,
    RESET_RCAR4_VIN0,
    RESET_RCAR4_ETHERAVB,
    RESET_RCAR4_SATA0,
    RESET_RCAR4_IMR3,
    RESET_RCAR4_IMR2,
    RESET_RCAR4_IMR1,
    RESET_RCAR4_IMR0,
    RESET_RCAR4_GPIO7,
    RESET_RCAR4_GPIO6,
    RESET_RCAR4_GPIO5,
    RESET_RCAR4_GPIO4,
    RESET_RCAR4_GPIO3,
    RESET_RCAR4_GPIO2,
    RESET_RCAR4_GPIO1,
    RESET_RCAR4_GPIO0,
    RESET_RCAR4_CAN_FD,
    RESET_RCAR4_CAN_IF1,
    RESET_RCAR4_CAN_IF0,
    RESET_RCAR4_I2C6,
    RESET_RCAR4_I2C5,
    RESET_RCAR4_I2C_DVFS,
    RESET_RCAR4_I2C4,
    RESET_RCAR4_I2C3,
    RESET_RCAR4_I2C2,
    RESET_RCAR4_I2C1,
    RESET_RCAR4_I2C0,
    RESET_RCAR4_SSI_ALL,
    RESET_RCAR4_SSI9,
    RESET_RCAR4_SSI8,
    RESET_RCAR4_SSI7,
    RESET_RCAR4_SSI6,
    RESET_RCAR4_SSI5,
    RESET_RCAR4_SSI4,
    RESET_RCAR4_SSI3,
    RESET_RCAR4_SSI2,
    RESET_RCAR4_SSI1,
    RESET_RCAR4_SSI0,
    RESET_RCAR4_COUNT,
};
#endif /* RCAR4_SCMI_ID_H */
