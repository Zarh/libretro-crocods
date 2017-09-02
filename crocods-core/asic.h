/**
 * @file
 * @author  Miguel Vanhove / Kyuran <crocods@kyuran.be>
 * @author  Kevin Thacker for the original version on Arnold (1995-2001)
 * @version 2.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * https://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * CPC+ ASIC Emulation
 */

#include  "crocods.h"
#include  "plateform.h"

#ifndef ASIC_H
#define ASIC_H

#ifdef __cplusplus
extern "C" {
#endif

BOOL InitASIC(core_crocods_t *core);

void    ASIC_Finish(void);

void    ASIC_InitCart(void);
void    ASIC_Reset(void);
void    ASIC_EnableDisable(int);
int     ASIC_DMA_GetChannelAddr(int);
int     ASIC_DMA_GetChannelPrescale(int);
unsigned char   *ASIC_GetCartPage(int);
void    ASIC_SetRasterInterrupt(void);
void    ASIC_ClearRasterInterrupt(void);

/*char    *ASIC_DebugDMACommand(int,int); */

unsigned char *ASIC_GetRamPtr(void);


unsigned long ASIC_BuildDisplayReturnMaskWithPixels(int Line, int HCount, /*int MonitorHorizontalCount, int ActualY,*/ int *pPixels);

void    ASIC_DoDMA(void);

void    ASIC_HSync(int,int);

/* asic functions to be executed when Htot reached */
void    ASIC_HTot(int);

int             ASIC_CalculateInterruptVector(void);

/* get lock state of ASIC (features locked/unlocked) for snapshot */
BOOL    ASIC_GetUnLockState(void);
/* set lock state of ASIC (features locked/unlocked) for snapshot */
void ASIC_SetUnLockState(BOOL);

void    ASIC_SetSecondaryRomMapping(unsigned char Data);
int ASIC_GetSecondaryRomMapping(void);

/* reset gate array in ASIC */
void    ASIC_GateArray_Reset(void);

/* trap writes to asic ram */
void    ASIC_WriteRam(int Addr,int Data);

/* used when setting up ASIC in reset or from snapshots */
void    ASIC_WriteRamFull(int Addr, int Data);

int Cartridge_AttemptInsert(unsigned char *pCartridgeData, unsigned long CartridgeLength);
int     Cartridge_Insert(const unsigned char *pCartridgeData, const unsigned long CartridgeDataLength);
void    Cartridge_Autostart(void);
void    Cartridge_Remove(void);

BOOL    ASIC_RasterIntEnabled(void);

void    ASIC_DoRomSelection(void);
void    ASIC_AcknowledgeInterrupt(void);

void    ASIC_DMA_EnableChannels(unsigned char);

/* debugger */
unsigned char   ASIC_GetRed(int);
unsigned char ASIC_GetGreen(int);
unsigned char ASIC_GetBlue(int);
unsigned char ASIC_GetSpritePixel(int SpriteIndex, int X, int Y);






#ifdef __cplusplus
}
#endif


#endif
