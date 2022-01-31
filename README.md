# LED_Desk_Light
Motion activated desk light. Built for rudimentary demonstration of human machine interaction interface


Used Arduino Micro with HC-SR501 PIR Motion sensors. Next, preference-based-learning is proposed to incorporate user-preferences to produce a more personalized actuator. This project will be used to demonstrate this concept with the LED bar acting as a lone actuator.

--------------
Shopping List:
LEDs: https://www.amazon.com/dp/B07FVR6W71?ref=nb_sb_ss_w_as-ypp-rep_ypp_rep_k3_1_8&amp&crid=1IAQKZJU8TX1Q&amp&sprefix=alitove+

Power supply: 5V supply, with 0.050 * NUM_LEDS Amps. In the case of a 300 LED strip, to power all LEDS at full brightness (without excessive power supply heat), you would need a 5V, 0.050 * 300 = (5V 15A) power supply. You can probably get away with a ~10A supply though in this case (multiply 0.050 * NUM_LEDS by 2/3). Just look up the specs you need on Amazon.

Any Arduino microcontroller board will do. I recommend either the Uno, Nano, or Micro. (Boards like the Mega and BLE are overkill unless you need their special capabilities): https://store-usa.arduino.cc/collections/boards/products/arduino-uno-rev3

Breadboard wire and breadboard: https://www.amazon.com/Standard-Jumper-Solderless-Prototype-Breadboard/dp/B07H7V1X7Y/ref=sr_1_6?crid=21PS6KYQCKJXL&keywords=breadboard&qid=1643638611&sprefix=breadbo%2Caps%2C179&sr=8-6

HC-SR501 PIR Motion sensors: https://www.amazon.com/HiLetgo-HC-SR501-Infrared-Sensor-Arduino/dp/B07KZW86YR/ref=sr_1_1_sspa?crid=2GZNO4R6I714Q&keywords=HC-SR501&qid=1643638586&sprefix=hc-sr501%2Caps%2C149&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExQzdVRU1GTE9SOFFUJmVuY3J5cHRlZElkPUEwNDcwMjEwQUtVSVA2MjhBU05LJmVuY3J5cHRlZEFkSWQ9QTA5MDUzNDczTEFKWjRKSU9LOEtPJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==

