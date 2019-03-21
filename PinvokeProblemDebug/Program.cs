using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

[StructLayout(LayoutKind.Sequential)]
struct p2
{
    public float x;
    public float y;
}

[StructLayout(LayoutKind.Sequential)]
struct p3
{
    public float x;
    public float y;
    public float z;
}

class Program
{
    [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
    static extern p2 getVec2();

    [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
    static extern p3 getVec3();

    static void Main(string[] args)
    {
        var vec3 = getVec3();
        var vec2 = getVec2();

        Console.WriteLine($"{vec3.x},{vec3.y},{vec3.z}");
        Console.WriteLine($"{vec2.x},{vec2.y}");

        Console.ReadKey();
    }
}