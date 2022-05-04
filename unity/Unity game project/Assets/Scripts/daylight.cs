using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class daylight : MonoBehaviour
{

    public GameObject go;
    private Light light;
    private float speed;

    // Start is called before the first frame update
    void Start()
    {
        light = go.GetComponent<Light>();
        light.enabled = false;
        speed = 10;
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 rot = new Vector3(0, 10.0f, 10.0f);
        transform.Rotate(transform.right * speed * Time.deltaTime);
        float pos = transform.rotation.x;
        Debug.Log("Posicion: " + pos); // Para ver cuando se hace de noche y de dia
    }
}
