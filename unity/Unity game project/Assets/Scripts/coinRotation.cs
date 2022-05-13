using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class coinRotation : MonoBehaviour {
    [SerializeField] private Vector3 _rotation;
    
    void Update() {
        transform.Rotate(_rotation * Time.deltaTime * 3);
    }
}
