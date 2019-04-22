/**
 ******************************************************************************
 * @file    stm32f3xx_it.c
 * @brief   Interrupt Service Routines.
 ******************************************************************************
 *
 * COPYRIGHT(c) 2019 STMicroelectronics
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"
#include "stm32f3xx.h"
#include "stm32f3xx_it.h"

/* USER CODE BEGIN 0 */
#include "motor.h"
extern volatile uint32_t g_timCount;
extern tarparameter g_targetTrans;
extern int Tra;
extern int tur;
extern float a;
extern float x;
extern float x_acc;
extern float x_dec;

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim6;

/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */
/******************************************************************************/

/**
 * @brief This function handles System tick timer.
 */
void SysTick_Handler(void) {
	/* USER CODE BEGIN SysTick_IRQn 0 */

	/* USER CODE END SysTick_IRQn 0 */
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
	/* USER CODE BEGIN SysTick_IRQn 1 */

	/* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F3xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f3xx.s).                    */
/******************************************************************************/

/**
 * @brief This function handles DMA1 channel1 global interrupt.
 */
void DMA1_Channel1_IRQHandler(void) {
	/* USER CODE BEGIN DMA1_Channel1_IRQn 0 */

	/* USER CODE END DMA1_Channel1_IRQn 0 */
	HAL_DMA_IRQHandler(&hdma_adc1);
	/* USER CODE BEGIN DMA1_Channel1_IRQn 1 */

	/* USER CODE END DMA1_Channel1_IRQn 1 */
}

/**
 * @brief This function handles TIM1 update and TIM16 interrupts.
 */
void TIM1_UP_TIM16_IRQHandler(void) {
	/* USER CODE BEGIN TIM1_UP_TIM16_IRQn 0 */
	uint16_t rightCount;
	/* USER CODE END TIM1_UP_TIM16_IRQn 0 */
	HAL_TIM_IRQHandler(&htim1);
	/* USER CODE BEGIN TIM1_UP_TIM16_IRQn 1 */
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
	rightCount = rightcalPWMCount(g_targetTrans.vel_r);
	__HAL_TIM_SET_AUTORELOAD(&htim1, rightCount);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, rightCount / 2);
	rightCWCCW(g_targetTrans.vel_r);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	/* USER CODE END TIM1_UP_TIM16_IRQn 1 */
}

/**
 * @brief This function handles TIM1 capture compare interrupt.
 */
void TIM1_CC_IRQHandler(void) {
	/* USER CODE BEGIN TIM1_CC_IRQn 0 */

	/* USER CODE END TIM1_CC_IRQn 0 */
	HAL_TIM_IRQHandler(&htim1);

	/* USER CODE END TIM1_CC_IRQn 1 */
}

/**
 * @brief This function handles TIM2 global interrupt.
 */
void TIM2_IRQHandler(void) {
	/* USER CODE BEGIN TIM2_IRQn 0 */
	uint16_t leftCount;
	/* USER CODE END TIM2_IRQn 0 */
	HAL_TIM_IRQHandler(&htim2);
	/* USER CODE BEGIN TIM2_IRQn 1 */
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
	leftCount = leftcalPWMCount(g_targetTrans.vel_l);
	__HAL_TIM_SET_AUTORELOAD(&htim2, leftCount);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, leftCount / 2);
	leftCWCCW(g_targetTrans.vel_l);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
	/* USER CODE END TIM2_IRQn 1 */
}

/**
 * @brief This function handles TIM3 global interrupt.
 */
void TIM3_IRQHandler(void) {
	/* USER CODE BEGIN TIM3_IRQn 0 */

	/* USER CODE END TIM3_IRQn 0 */
	HAL_TIM_IRQHandler(&htim3);
	/* USER CODE BEGIN TIM3_IRQn 1 */

	/* USER CODE END TIM3_IRQn 1 */
}

/**
 * @brief This function handles TIM6 global and DAC1 underrun error interrupts.
 */
void TIM6_DAC1_IRQHandler(void) {
	/* USER CODE BEGIN TIM6_DAC1_IRQn 0 */

	/* USER CODE END TIM6_DAC1_IRQn 0 */
	HAL_TIM_IRQHandler(&htim6);
	/* USER CODE BEGIN TIM6_DAC1_IRQn 1 */
	g_timCount++;

	if (Tra == 1) {
		rightcalPara(&g_targetTrans);//右左いらないかも
		if (g_targetTrans.dis < x_acc) {
			g_targetTrans.vel_r += a * 0.001;
			g_targetTrans.vel_l += a * 0.001;
		} else if (g_targetTrans.dis < (x - x_dec)) {
			g_targetTrans.vel_r += 0 * 0.001;
			g_targetTrans.vel_l += 0 * 0.001;
		} else {
			g_targetTrans.vel_r -= a * 0.001;
			g_targetTrans.vel_l -= a * 0.001;
		}
	}
	if (tur == 1) {
		rightcalPara(&g_targetTrans);
		leftcalPara(&g_targetTrans);
	}
	/* USER CODE END TIM6_DAC1_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
