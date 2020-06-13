using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.Rendering;

public class CubeManager : MonoBehaviour
{
    private bool can = true;
    
    public GameObject CubePrefPice;
    Transform CubeTrunsf;
    List<GameObject> AllCubePices = new List<GameObject>();
    private GameObject CubeCenterPice;
    private bool canRotate = true;

    List<GameObject> UpPices
    {
        get { return AllCubePices.FindAll(x => Mathf.Round(x.transform.localPosition.y) == 0); }
    }
    List<GameObject> DownPices
    {
        get { return AllCubePices.FindAll(x => Mathf.Round(x.transform.localPosition.y) == -2); }
        
    }
    List<GameObject> FrontPices
    {
        get { return AllCubePices.FindAll(x => Mathf.Round(x.transform.localPosition.x) == 0); }
    }
    List<GameObject> BackPices
    {
        get { return AllCubePices.FindAll(x => Mathf.Round(x.transform.localPosition.x) == -2); }
    }
    List<GameObject> LeftPices
    {
        get { return AllCubePices.FindAll(x => Mathf.Round(x.transform.localPosition.z) == 0); }
    }
    List<GameObject> RightPices
    {
        get { return AllCubePices.FindAll(x => Mathf.Round(x.transform.localPosition.z) == 2); }
    }
    
    void Start()
    {
        CreateCube();
    }
    
    void Update()
    {
        if (canRotate)
        {
            CheckInput();
        }
    }

    void CreateCube()
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                for (int z = 0; z < 3; z++)
                {
                    GameObject go = Instantiate(CubePrefPice, CubeTrunsf, false);
                    
                    go.transform.localPosition = new Vector3(-x, -y, z);
                    
                    AllCubePices.Add(go);
                }
            }
        }

        CubeCenterPice = AllCubePices[13];
    }

    void CheckInput()
    {
        if (Input.GetKey(KeyCode.Q))
        {
            StartCoroutine(Rotate(UpPices, new Vector3(0, 1, 0))); //up
        }
        else if (Input.GetKey(KeyCode.W))
        {
            StartCoroutine(Rotate(UpPices, new Vector3(0, -1, 0))); //up'
        }
        else if (Input.GetKey(KeyCode.A))
        {
            StartCoroutine(Rotate(DownPices, new Vector3(0, -1, 0))); //Down
        }
        else if (Input.GetKey(KeyCode.S))
        {
            StartCoroutine(Rotate(DownPices, new Vector3(0, 1, 0))); //Down'
        }
        else if (Input.GetKey(KeyCode.Z))
        {
            StartCoroutine(Rotate(LeftPices, new Vector3(0, 0, -1))); //Left
        }
        else if (Input.GetKey(KeyCode.X))
        {
            StartCoroutine(Rotate(LeftPices, new Vector3(0, 0, 1))); //Left'
        }
        else if (Input.GetKey(KeyCode.C))
        {
            StartCoroutine(Rotate(RightPices, new Vector3(0, 0, 1))); //Right
        }
        else if (Input.GetKey(KeyCode.V))
        {
            StartCoroutine(Rotate(RightPices, new Vector3(0, 0, -1))); //Right'
        }
        else if (Input.GetKey(KeyCode.E))
        {
            StartCoroutine(Rotate(FrontPices, new Vector3(1, 0, 0))); //Front
        }
        else if (Input.GetKey(KeyCode.R))
        {
            StartCoroutine(Rotate(FrontPices, new Vector3(-1, 0, 0))); //Front'
        }
        else if (Input.GetKey(KeyCode.D))
        {
            StartCoroutine(Rotate(BackPices, new Vector3(-1, 0, 0))); //Back
        }
        else if (Input.GetKey(KeyCode.F))
        {
            StartCoroutine(Rotate(BackPices, new Vector3(1, 0, 0))); //Back'
        }
        else if (Input.GetKey(KeyCode.KeypadEnter))
        {
            string[] readText = File.ReadAllLines("C:\\Users\\danil\\Desktop\\u_c\\solve.txt");

            Debug.Log(readText.Length);
            
            foreach (string s in readText)
            {
                if (s == "U")
                {
                    StartCoroutine(Rotate(UpPices, new Vector3(0, 1, 0)));
                 
                }
                else if (s == "Z")
                {
                    StartCoroutine(Rotate(UpPices, new Vector3(0, -1, 0)));
                   
                }
                else if (s == "D")
                {
                    StartCoroutine(Rotate(DownPices, new Vector3(0, -1, 0)));
                
                }
                else if (s == "X")
                {
                    StartCoroutine(Rotate(DownPices, new Vector3(0, 1, 0)));
               
                }
                else if (s == "L")
                {
                    StartCoroutine(Rotate(LeftPices, new Vector3(0, 0, -1)));
               
                }
                else if (s == "C")
                {
                    StartCoroutine(Rotate(LeftPices, new Vector3(0, 0, 1)));
                
                }
                else if (s == "R")
                {
                    StartCoroutine(Rotate(RightPices, new Vector3(0, 0, 1)));
            
                }
                else if (s == "V")
                {
                    StartCoroutine(Rotate(RightPices, new Vector3(0, 0, -1)));
               
                }
                else if (s == "F")
                {
                    StartCoroutine(Rotate(FrontPices, new Vector3(1, 0, 0)));
                 
                }
                else if (s == "N")
                {
                    StartCoroutine(Rotate(FrontPices, new Vector3(-1, 0, 0)));
                
                }
                else if (s == "B")
                {
                    StartCoroutine(Rotate(BackPices, new Vector3(-1, 0, 0)));
        
                }
                else if (s == "M")
                {
                    StartCoroutine(Rotate(BackPices, new Vector3(1, 0, 0)));
             
                }
            }
        }
        else if (Input.GetKey(KeyCode.Space))
        {
            string[] readText = File.ReadAllLines("C:\\Users\\danil\\Desktop\\u_c\\invert_solve.txt");
        
            Debug.Log(readText.Length);
            
            foreach (string s in readText)
            {
                if (s == "U")
                {
                    StartCoroutine(Rotate(UpPices, new Vector3(0, 1, 0)));
           
                }
                else if (s == "Z")
                {
                    StartCoroutine(Rotate(UpPices, new Vector3(0, -1, 0)));
            
                }
                else if (s == "D")
                {
                   StartCoroutine(Rotate(DownPices, new Vector3(0, -1, 0)));
          
                }
                else if (s == "X")
                {
                    StartCoroutine(Rotate(DownPices, new Vector3(0, 1, 0)));
                
                }
                else if (s == "L")
                {
                    StartCoroutine(Rotate(LeftPices, new Vector3(0, 0, -1)));
        
                }
                else if (s == "C")
                {
                    StartCoroutine(Rotate(LeftPices, new Vector3(0, 0, 1)));
                 
                }
                else if (s == "R")
                {
                    StartCoroutine(Rotate(RightPices, new Vector3(0, 0, 1)));
               
                }
                else if (s == "V")
                {
                    StartCoroutine(Rotate(RightPices, new Vector3(0, 0, -1)));
              
                }
                else if (s == "F")
                {
                    StartCoroutine(Rotate(FrontPices, new Vector3(1, 0, 0)));
               
                }
                else if (s == "N")
                {
                    StartCoroutine(Rotate(FrontPices, new Vector3(-1, 0, 0)));
                  
                }
                else if (s == "B" )
                {
                    StartCoroutine(Rotate(BackPices, new Vector3(-1, 0, 0)));
                    
                  
                }
                else if (s == "M")
                {
                    StartCoroutine(Rotate(BackPices, new Vector3(1, 0, 0)));
                }
            }
        }
    }

    public void On_click()
    {
        //CreateCube();
    }

   
    IEnumerator Rotate(List<GameObject> pices, Vector3 rotationVec)
    {
        canRotate = false;
        int angle = 0;

        while (angle < 90)
        {
            foreach (GameObject go in pices)
            {
                go.transform.RotateAround(CubeCenterPice.transform.position, rotationVec, 2);
                
            }
            
            angle += 2;
            yield return null;
        }
        
        canRotate = true;
    }
}