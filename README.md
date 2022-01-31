# LED_Desk_Light
Motion activated desk light. Built for rudimentary demonstration of human machine interaction interface


Used Arduino Micro with HC-SR501 PIR Motion sensors. Next, preference-based-learning is proposed to incorporate user-preferences to produce a more personalized actuator. This project will be used to demonstrate this concept with the LED bar acting as a lone actuator.

--------------
Shopping List:
LEDs: https://www.amazon.com/dp/B07FVR6W71?ref=nb_sb_ss_w_as-ypp-rep_ypp_rep_k3_1_8&amp&crid=1IAQKZJU8TX1Q&amp&sprefix=alitove+

Power supply: 5V supply, with 0.050 * NUM_LEDS Amps. In the case of a 300 LED strip, to power all LEDS at full brightness (without excessive power supply heat), you would need a 5V, 0.050 * 300 = (5V 15A) power supply. You can probably get away with a ~10A supply though in this case (multiply 0.050 * NUM_LEDS by 2/3).

Any Arduino microcontroller board will do. I recommend either the Uno, Nano, or Micro. (Boards like the Mega and BLE are overkill unless you need their special capabilities).

Breadboard wire and breadboard

HC-SR501 PIR Motion sensors
