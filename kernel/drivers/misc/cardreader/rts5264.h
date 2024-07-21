/* SPDX-License-Identifier: GPL-2.0-only */
/* Driver for Realtek PCI-Express card reader
 *
 * Copyright(c) 2018-2019 Realtek Semiconductor Corp. All rights reserved.
 *
 * Author:
 *   Ricky Wu <ricky_wu@realtek.com>
 */
#ifndef RTS5264_H
#define RTS5264_H

/*New add*/
#define rts5264_vendor_setting_valid(reg)	((reg) & 0x010000)
#define rts5264_reg_to_aspm(reg) \
	(((~(reg) >> 28) & 0x02) | (((reg) >> 28) & 0x01))
#define rts5264_reg_check_reverse_socket(reg)	((reg) & 0x04)
#define rts5264_reg_to_sd30_drive_sel_1v8(reg)	(((reg) >> 22) & 0x03)
#define rts5264_reg_to_sd30_drive_sel_3v3(reg)	(((reg) >> 16) & 0x03)
#define rts5264_reg_to_rtd3(reg)		((reg) & 0x08)

#define RTS5264_AUTOLOAD_CFG0		0xFF7B
#define RTS5264_AUTOLOAD_CFG1		0xFF7C
#define RTS5264_AUTOLOAD_CFG3		0xFF7E
#define RTS5264_AUTOLOAD_CFG4		0xFF7F
#define RTS5264_FORCE_PRSNT_LOW		(1 << 6)
#define RTS5264_AUX_CLK_16M_EN		(1 << 5)
#define RTS5264_F_HIGH_RC_MASK		(1 << 4)
#define RTS5264_F_HIGH_RC_1_6M		(1 << 4)
#define RTS5264_F_HIGH_RC_400K		(0 << 4)

/* SSC_CTL2 0xFC12 */
#define RTS5264_SSC_DEPTH_MASK		0x07
#define RTS5264_SSC_DEPTH_DISALBE	0x00
#define RTS5264_SSC_DEPTH_8M		0x01
#define RTS5264_SSC_DEPTH_4M		0x02
#define RTS5264_SSC_DEPTH_2M		0x03
#define RTS5264_SSC_DEPTH_1M		0x04
#define RTS5264_SSC_DEPTH_512K		0x05
#define RTS5264_SSC_DEPTH_256K		0x06
#define RTS5264_SSC_DEPTH_128K		0x07

#define RTS5264_CARD_CLK_SRC2		0xFC2F
#define RTS5264_REG_BIG_KVCO_A		0x20

/* efuse control register*/
#define RTS5264_EFUSE_CTL		0xFC30
#define RTS5264_EFUSE_ENABLE		0x80
/* EFUSE_MODE: 0=READ 1=PROGRAM */
#define RTS5264_EFUSE_MODE_MASK		0x40
#define RTS5264_EFUSE_PROGRAM		0x40

#define RTS5264_EFUSE_ADDR		0xFC31
#define	RTS5264_EFUSE_ADDR_MASK		0x3F

#define RTS5264_EFUSE_WRITE_DATA	0xFC32
#define RTS5264_EFUSE_READ_DATA		0xFC34

#define RTS5264_SYS_DUMMY_1		0xFC35
#define RTS5264_REG_BIG_KVCO		0x04

/* DMACTL 0xFE2C */
#define RTS5264_DMA_PACK_SIZE_MASK	0x70

#define RTS5264_FW_CFG1			0xFF55
#define RTS5264_SYS_CLK_SEL_MCU_CLK	(0x01<<7)
#define RTS5264_CRC_CLK_SEL_MCU_CLK	(0x01<<6)
#define RTS5264_FAKE_MCU_CLOCK_GATING	(0x01<<5)
#define RTS5264_MCU_BUS_SEL_MASK	(0x01<<4)

/* FW status register */
#define RTS5264_FW_STATUS		0xFF56
#define RTS5264_EXPRESS_LINK_FAIL_MASK	(0x01<<7)

/* FW control register */
#define RTS5264_FW_CTL			0xFF5F
#define RTS5264_INFORM_RTD3_COLD	(0x01<<5)

#define RTS5264_REG_FPDCTL		0xFF60

#define RTS5264_REG_LDO12_CFG		0xFF6E
#define RTS5264_LDO12_SR_MASK		(0x03<<6)
#define RTS5264_LDO12_SR_1_0_MS		(0x03<<6)
#define RTS5264_LDO12_SR_0_5_MS		(0x02<<6)
#define RTS5264_LDO12_SR_0_2_5_MS	(0x01<<6)
#define RTS5264_LDO12_SR_0_0_MS		(0x00<<6)
#define RTS5264_LDO12_VO_TUNE_MASK	(0x07<<1)
#define RTS5264_LDO12_115		(0x03<<1)
#define RTS5264_LDO12_120		(0x04<<1)
#define RTS5264_LDO12_125		(0x05<<1)
#define RTS5264_LDO12_130		(0x06<<1)
#define RTS5264_LDO12_135		(0x07<<1)

/* LDO control register */
#define RTS5264_CARD_PWR_CTL		0xFD50
#define RTS5264_SD_CLK_ISO		(0x01<<7)
#define RTS5264_PAD_SD_DAT_FW_CTRL	(0x01<<6)
#define RTS5264_PUPDC			(0x01<<5)
#define RTS5264_SD_CMD_ISO		(0x01<<4)

#define RTS5264_OCP_VDD3_CTL		0xFD89
#define SD_VDD3_DETECT_EN		0x08
#define SD_VDD3_OCP_INT_EN		0x04
#define SD_VDD3_OCP_INT_CLR		0x02
#define SD_VDD3_OC_CLR			0x01

#define RTS5264_OCP_VDD3_STS		0xFD8A
#define SD_VDD3_OCP_DETECT		0x08
#define SD_VDD3_OC_NOW			0x04
#define SD_VDD3_OC_EVER			0x02

#define RTS5264_OVP_CTL			0xFD8D
#define RTS5264_OVP_TIME_MASK		0xF0
#define RTS5264_OVP_TIME_DFT		0x50
#define RTS5264_OVP_DETECT_EN		0x08
#define RTS5264_OVP_INT_EN		0x04
#define RTS5264_OVP_INT_CLR		0x02
#define RTS5264_OVP_CLR			0x01

#define RTS5264_OVP_STS			0xFD8E
#define RTS5264_OVP_GLTCH_TIME_MASK	0xF0
#define RTS5264_OVP_GLTCH_TIME_DFT	0x50
#define RTS5264_VOVER_DET		0x08
#define RTS5264_OVP_NOW			0x04
#define RTS5264_OVP_EVER		0x02

#define RTS5264_CMD_OE_START_EARLY		0xFDCB
#define RTS5264_CMD_OE_EARLY_LEAVE		0x08
#define RTS5264_CMD_OE_EARLY_CYCLE_MASK		0x06
#define RTS5264_CMD_OE_EARLY_4CYCLE		0x06
#define RTS5264_CMD_OE_EARLY_3CYCLE		0x04
#define RTS5264_CMD_OE_EARLY_2CYCLE		0x02
#define RTS5264_CMD_OE_EARLY_1CYCLE		0x00
#define RTS5264_CMD_OE_EARLY_EN			0x01

#define RTS5264_DAT_OE_START_EARLY		0xFDCC
#define RTS5264_DAT_OE_EARLY_LEAVE		0x08
#define RTS5264_DAT_OE_EARLY_CYCLE_MASK		0x06
#define RTS5264_DAT_OE_EARLY_4CYCLE		0x06
#define RTS5264_DAT_OE_EARLY_3CYCLE		0x04
#define RTS5264_DAT_OE_EARLY_2CYCLE		0x02
#define RTS5264_DAT_OE_EARLY_1CYCLE		0x00
#define RTS5264_DAT_OE_EARLY_EN			0x01

#define RTS5264_LDO1233318_POW_CTL	0xFF70
#define RTS5264_TUNE_REF_LDO3318	(0x03<<6)
#define RTS5264_TUNE_REF_LDO3318_DFT	(0x02<<6)
#define RTS5264_LDO3318_POWERON		(0x01<<3)
#define RTS5264_LDO3_POWERON		(0x01<<2)
#define RTS5264_LDO2_POWERON		(0x01<<1)
#define RTS5264_LDO1_POWERON		(0x01<<0)
#define RTS5264_LDO_POWERON_MASK	(0x0F<<0)

#define RTS5264_DV3318_CFG		0xFF71
#define RTS5264_DV3318_TUNE_MASK	(0x07<<4)
#define RTS5264_DV3318_18		(0x02<<4)
#define RTS5264_DV3318_19		(0x04<<4)
#define RTS5264_DV3318_33		(0x07<<4)

#define RTS5264_LDO1_CFG0		0xFF72
#define RTS5264_LDO1_OCP_THD_MASK	(0x07 << 5)
#define RTS5264_LDO1_OCP_EN		(0x01 << 4)
#define RTS5264_LDO1_OCP_LMT_THD_MASK	(0x03 << 2)
#define RTS5264_LDO1_OCP_LMT_EN		(0x01 << 1)

#define RTS5264_LDO1_OCP_THD_850	(0x00<<5)
#define RTS5264_LDO1_OCP_THD_950	(0x01<<5)
#define RTS5264_LDO1_OCP_THD_1050	(0x02<<5)
#define RTS5264_LDO1_OCP_THD_1100	(0x03<<5)
#define RTS5264_LDO1_OCP_THD_1150	(0x04<<5)
#define RTS5264_LDO1_OCP_THD_1200	(0x05<<5)
#define RTS5264_LDO1_OCP_THD_1300	(0x06<<5)
#define RTS5264_LDO1_OCP_THD_1350	(0x07<<5)

#define RTS5264_LDO1_LMT_THD_1700	(0x00<<2)
#define RTS5264_LDO1_LMT_THD_1800	(0x01<<2)
#define RTS5264_LDO1_LMT_THD_1900	(0x02<<2)
#define RTS5264_LDO1_LMT_THD_2000	(0x03<<2)

#define RTS5264_LDO1_CFG1		0xFF73
#define RTS5264_LDO1_TUNE_MASK		(0x07<<1)
#define RTS5264_LDO1_18			(0x05<<1)
#define RTS5264_LDO1_33			(0x07<<1)
#define RTS5264_LDO1_PWD_MASK		(0x01<<0)

#define RTS5264_LDO2_CFG0		0xFF74
#define RTS5264_LDO2_OCP_THD_MASK	(0x07<<5)
#define RTS5264_LDO2_OCP_EN		(0x01<<4)
#define RTS5264_LDO2_OCP_LMT_THD_MASK	(0x03<<2)
#define RTS5264_LDO2_OCP_LMT_EN		(0x01<<1)

#define RTS5264_LDO2_OCP_THD_750	(0x00<<5)
#define RTS5264_LDO2_OCP_THD_850	(0x01<<5)
#define RTS5264_LDO2_OCP_THD_900	(0x02<<5)
#define RTS5264_LDO2_OCP_THD_950	(0x03<<5)
#define RTS5264_LDO2_OCP_THD_1050	(0x04<<5)
#define RTS5264_LDO2_OCP_THD_1100	(0x05<<5)
#define RTS5264_LDO2_OCP_THD_1150	(0x06<<5)
#define RTS5264_LDO2_OCP_THD_1200	(0x07<<5)

#define RTS5264_LDO2_LMT_THD_1700	(0x00<<2)
#define RTS5264_LDO2_LMT_THD_1800	(0x01<<2)
#define RTS5264_LDO2_LMT_THD_1900	(0x02<<2)
#define RTS5264_LDO2_LMT_THD_2000	(0x03<<2)

#define RTS5264_LDO2_CFG1		0xFF75
#define RTS5264_LDO2_TUNE_MASK		(0x07<<1)
#define RTS5264_LDO2_18			(0x02<<1)
#define RTS5264_LDO2_185		(0x03<<1)
#define RTS5264_LDO2_19			(0x04<<1)
#define RTS5264_LDO2_195		(0x05<<1)
#define RTS5264_LDO2_33			(0x07<<1)
#define RTS5264_LDO2_PWD_MASK		(0x01<<0)

#define RTS5264_LDO3_CFG0		0xFF76
#define RTS5264_LDO3_OCP_THD_MASK	(0x07<<5)
#define RTS5264_LDO3_OCP_EN		(0x01<<4)
#define RTS5264_LDO3_OCP_LMT_THD_MASK	(0x03<<2)
#define RTS5264_LDO3_OCP_LMT_EN		(0x01<<1)

#define RTS5264_LDO3_OCP_THD_610	(0x00<<5)
#define RTS5264_LDO3_OCP_THD_630	(0x01<<5)
#define RTS5264_LDO3_OCP_THD_670	(0x02<<5)
#define RTS5264_LDO3_OCP_THD_710	(0x03<<5)
#define RTS5264_LDO3_OCP_THD_750	(0x04<<5)
#define RTS5264_LDO3_OCP_THD_770	(0x05<<5)
#define RTS5264_LDO3_OCP_THD_810	(0x06<<5)
#define RTS5264_LDO3_OCP_THD_850	(0x07<<5)

#define RTS5264_LDO3_LMT_THD_1200	(0x00<<2)
#define RTS5264_LDO3_LMT_THD_1300	(0x01<<2)
#define RTS5264_LDO3_LMT_THD_1400	(0x02<<2)
#define RTS5264_LDO3_LMT_THD_1500	(0x03<<2)

#define RTS5264_LDO3_CFG1		0xFF77
#define RTS5264_LDO3_TUNE_MASK		(0x07<<1)
#define RTS5264_LDO3_12			(0x02<<1)
#define RTS5264_LDO3_125		(0x03<<1)
#define RTS5264_LDO3_13			(0x04<<1)
#define RTS5264_LDO3_135		(0x05<<1)
#define RTS5264_LDO3_33			(0x07<<1)
#define RTS5264_LDO3_PWD_MASK		(0x01<<0)

#define RTS5264_REG_PME_FORCE_CTL	0xFF78
#define FORCE_PM_CONTROL		0x20
#define FORCE_PM_VALUE			0x10
#define REG_EFUSE_BYPASS		0x08
#define REG_EFUSE_POR			0x04
#define REG_EFUSE_POWER_MASK		0x03
#define REG_EFUSE_POWERON		0x03
#define REG_EFUSE_POWEROFF		0x00

#define RTS5264_PWR_CUT			0xFF81
#define RTS5264_CFG_MEM_PD		0xF0

#define RTS5264_OVP_DET			0xFF8A
#define RTS5264_POW_VDET		0x04
#define RTS5264_TUNE_VROV_MASK		0x03
#define RTS5264_TUNE_VROV_2V		0x03
#define RTS5264_TUNE_VROV_1V8		0x02
#define RTS5264_TUNE_VROV_1V6		0x01
#define RTS5264_TUNE_VROV_1V4		0x00

#define RTS5264_CKMUX_MBIAS_PWR		0xFF8B
#define RTS5264_NON_XTAL_SEL		0x80
#define RTS5264_POW_CKMUX		0x40
#define RTS5264_LVD_MASK		0x04
#define RTS5264_POW_PSW_MASK		0x03
#define RTS5264_POW_PSW_DFT		0x03

/* Single LUN, support SD/SD EXPRESS */
#define DEFAULT_SINGLE		0
#define SD_LUN			1
#define SD_EXPRESS_LUN		2

int rts5264_pci_switch_clock(struct rtsx_pcr *pcr, unsigned int card_clock,
		u8 ssc_depth, bool initial_mode, bool double_clk, bool vpclk);

#endif /* RTS5264_H */
