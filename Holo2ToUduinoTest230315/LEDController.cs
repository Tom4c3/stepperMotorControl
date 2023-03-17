using UnityEngine;
using System.Collections;
using Uduino;

public class LEDController : MonoBehaviour
{
   

    void Start()
    {
    }

    public void TurnOnLED()
    {
        // ESP32にシリアル通信でコマンドを送信
        UduinoManager.Instance.sendCommand("onLED", 255);

       // Debug.Log("Turn on button is pressed!");
    }

    public void TurnOffLED()
    {
        // ESP32にシリアル通信でコマンドを送信
        UduinoManager.Instance.sendCommand("offLED", 0);

        //Debug.Log("Turn off button is pressed!");
    }

}
