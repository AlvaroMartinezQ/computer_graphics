using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class creditos : MonoBehaviour
{
    void Start()
    {
        Invoke("WaitToEnd", 30);
    }

    void Update()
    {
        if (Input.GetKey(KeyCode.Escape))
        {
            SceneManager.LoadScene("Scene1");
        }
    }
    public void WaitToEnd()
    {
        SceneManager.LoadScene("Scene1");
    }
}
