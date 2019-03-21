using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

struct p2
{
    public uint x,y;
}

struct p3
{
    public uint x,y,z;
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

        Console.WriteLine(vec3.x);
        Console.WriteLine(vec2.x);

        Console.ReadKey();
    }
}