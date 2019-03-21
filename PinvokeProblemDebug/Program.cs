using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

struct p2
{
    public ulong x;
}

struct pv2
{
    public float x,y,z;
}

public partial struct PxVec3
{
    // blittable
    public float x;
    public float y;
    public float z;
}

class Program
{
    [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
    static extern p2 getVal();

    [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
    static extern pv2 getVec();

    [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
    static extern PxVec3 getVec3();

    static void Main(string[] args)
    {
        var vec3 = getVec3();

        var vec = getVec();

        Console.WriteLine(vec3.x);
        Console.WriteLine(vec.x);

        Console.ReadKey();
        //var val = getVal();
    }
}