void EXTI1_IRQHandler(void)
{ 
    //JOY_LEFT pressed
    NVIC_ClearPendingIRQ(EXTI1_IRQn); 
    if((GPIOC->IDR >> JOY_LEFT) & 0x1)
    {
        done = 1;
        EXTI->PR |= (0x01 << JOY_LEFT);
    } 
} 

void EXTI4_IRQHandler(void)
{ 
    // JOY_UP pressed
    NVIC_ClearPendingIRQ(EXTI4_IRQn);
	if((GPIOA->IDR >> JOY_UP) & 0x1)
    {
        done = 3;
        EXTI->PR |= (0x01 << JOY_UP);
    }
} 

void EXTI9_5_IRQHandler(void)
{
    //JOY_CENTER pressed
    NVIC_ClearPendingIRQ(EXTI9_5_IRQn);
	if((GPIOB->IDR >> JOY_CENTER) & 0x1)
    {
        done = 4;
        EXTI->PR |= (0x01 << JOY_CENTER); 
    }
}

