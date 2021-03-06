#ifndef APPH_CARD_H_
#define APPH_CARD_H_


/* ------------------------------------------------------------------------------------------------
 *                                          Includes
 * ------------------------------------------------------------------------------------------------
 */

#include <string.h>

/* 应用层 */
#include "appl_data.h"



/* 设备层 */
#include "dev_mfrc522.h"
#include "dev_buzzer.h"


/* 配置层 */
#include "Config.h"




/* ------------------------------------------------------------------------------------------------
 *                                          Define
 * ------------------------------------------------------------------------------------------------
 */

/********************M1卡区块************************/

/*62块放置卡号基本信息*/
#define BlockSize            16       //一个块16个字节
#define CARD_INFORMATION     62       //M1卡第62块，放入卡片的基本信息

/******************卡号基本信息*********************/
/*M1卡权限类型-CardType(2byte)*/
#define Authorization     0x01        //授权卡
#define UnAuthorizataion  0x02        //删权卡
//#define NullCard          0x03      //空卡
#define TotalCard         0x04        //总卡
#define FloorCard         0x05        //楼层卡
//#define OrdinaryCard      0x10      //普通卡


/******************M1卡操作类型*********************/
#define READ_ID       1               //读卡号ID
#define WRITE_BLOCK   2               //写入区块数据
#define READ_BLOCK    3               //读取区块数据



//门锁授权最大等待时间，20*100 = 2000ms
#define READNUM             15      //这个不能太大，应该保持足够小
#define TIMESPACE           200     //每250ms读取一次有没有卡，这个数值不能太小



/* ------------------------------------------------------------------------------------------------
 *                                          variable
 * ------------------------------------------------------------------------------------------------
 */




/* ------------------------------------------------------------------------------------------------
 *                                          Applications
 * ------------------------------------------------------------------------------------------------
 */
void Card_Init(void);
uint8 Card_Authorization(uint8 CardOperType,uint8 *DoorId);

/* ------------------------------------------------------------------------------------------------
 *                                          Middle
 * ------------------------------------------------------------------------------------------------
 */
uint8 Card_ReadID(uint8 BlockAddr, uint8 *CardId);
uint8 Card_WriteBlock(uint8 BlockAddr, uint8 *BlockData);
uint8 Card_ReadBlock(uint8 BlockAddr, uint8 *BlockData);

/* ------------------------------------------------------------------------------------------------
 *                                          Prototypes
 * ------------------------------------------------------------------------------------------------
 */
uint8 Card_Process(uint8 *CardId, uint8 BlockAddr, uint8 *BlockData, uint8 ProcessType);


#endif