using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class coinCollect : MonoBehaviour
{
    public int coins;
    public AudioSource source;
    public AudioClip clip;
    
    public void OnTriggerEnter(Collider col) {
        if (col.gameObject.tag == "Coin") {
            // Debug.Log("Coin");
            source.PlayOneShot(clip);
            coins = coins + 1;
            Destroy(col.gameObject);
        }
    }
}
