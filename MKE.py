import serial
import pyautogui

Arduino_Serial = serial.Serial('com9',9600)
 
while 1:
    incoming_data = str (Arduino_Serial.readline())
    #print ('OK')
    #print (incoming_data)

    if 'Left' in incoming_data:
        pyautogui.press('left')
        
    if 'Up' in incoming_data:
        pyautogui.press('up')

    if 'Down' in incoming_data:
        pyautogui.press('down')

    if 'Right' in incoming_data:
        pyautogui.press('right')

    if 'OK' in incoming_data:
        pyautogui.press('space')
        
    if '*' in incoming_data:
        pyautogui.press('f')

    if '1' in incoming_data:
        pyautogui.moveRel(-15,-15,0.0,pyautogui.easeInQuad)
        
    if '2' in incoming_data:
        pyautogui.moveRel(0,-15,0.0,pyautogui.easeInQuad)
        
    if '3' in incoming_data:
        pyautogui.moveRel(15,-15,0.0,pyautogui.easeInQuad)

    if '4' in incoming_data:
        pyautogui.moveRel(-15,0,0.0,pyautogui.easeInQuad)

    if '5' in incoming_data:
        pyautogui.click(button='middle')

    if '6' in incoming_data:
        pyautogui.moveRel(15,0,0.0,pyautogui.easeInQuad)

    if '7' in incoming_data:
        pyautogui.moveRel(-15,15,0.0,pyautogui.easeInQuad)

    if '8' in incoming_data:
        pyautogui.moveRel(0,15,0.0,pyautogui.easeInQuad)

    if '9' in incoming_data:
        pyautogui.moveRel(15,15,0.0,pyautogui.easeInQuad)

    if '0' in incoming_data:
        pyautogui.click()

    if '#' in incoming_data:
        pyautogui.click(button='right')
        
    incoming_data = "";
