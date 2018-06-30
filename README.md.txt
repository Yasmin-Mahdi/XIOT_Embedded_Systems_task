

-Atmega32 file is the datasheet which I used to implement my driver.

-the code is wrriten in c language using eclipse IDE.
 
-I used pin A0 as input for temperature sensor.

-I used pin D2 as input for interrupt.

-I used pin D3 as output for LED.

-you are free to change the ports in case u have your own design but you should go to the "DIO_config.h" and configure the used pin as input or output and if you want to change the channel which you use to read the temperature
you have to chose only any pins in PORT A because they only allow ADC in this MC and you should configure this pin as input in "DIO_config.h" file.
and you should change this function "ADC_voidStartConv(zero);" to take any number between zero and seven according to 
the chossed chanel. 

- if you want to change the design please don't change the switch pin because it is designed on the interrupt pin of interrupt0 and processor can only be interrupted from this pin.

-I  divided the system to MCAL ,HAL and application layers according to autosar.

-the code is delivered by comments to clarify the idea.