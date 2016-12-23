#ifndef DRI_BUZZER_H_
#define DRI_BUZZER_H_

/* ------------------------------------------------------------------------------------------------
 *                                          Includes
 * ------------------------------------------------------------------------------------------------
 */
#include<ioCC2530.h>


/* ------------------------------------------------------------------------------------------------
 *                                          Define
 * ------------------------------------------------------------------------------------------------
 */

/*蜂鸣器端口宏定义*/
#define BUZZER          P2_0
#define BUZZER_IN()     P2DIR &= ~0x01
#define BUZZER_OUT()    P2DIR |=  0x01
#define BUZZER_IO()     P2SEL &= ~0x01              //普通IO口
#define BUZZER_T4()     P2SEL |=  0x01              //T4用作PWM输出    
#define BUZZER_T4ON()   T4CTL |=  0x10;             //启动定时器
#define BUZZER_T4OFF()  T4CTL &= ~0x10;             //关闭定时器
#define BUZZER_OFF()    BUZZER_IN();BUZZER_IO();BUZZER_T4OFF()
#define BUZZER_ON()     BUZZER_OUT();BUZZER_T4();BUZZER_T4ON()


 

/* ------------------------------------------------------------------------------------------------
 *                                          Prototypes
 * ------------------------------------------------------------------------------------------------
 */
void Buzzer_Init(void);
void Buzzer_Timer4_Init(void);

/**************************************************************************************************
 */
#endif