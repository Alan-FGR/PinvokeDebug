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
    static extern void getVec2ref(out p2 val);

    [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
    static extern p2 getVec2fix();

    [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
    static extern p3 getVec3();

    [DllImport("Dll.dll", CallingConvention = CallingConvention.Cdecl)]
    static extern void addVec2(out p2 result, in p2 a, in p2 b);

    static void Main(string[] args)
    {
        var vec3 = getVec3();
        var vec2 = getVec2();
        var vec2f = getVec2fix();
        getVec2ref(out var vec2r);
        addVec2(out var added, vec2r, vec2f);

        Console.WriteLine($"{vec3.x},{vec3.y},{vec3.z}");
        Console.WriteLine($"{vec2.x},{vec2.y}");
        Console.WriteLine($"{vec2f.x},{vec2f.y}");
        Console.WriteLine($"{vec2r.x},{vec2r.y}");
        Console.WriteLine($"added {added.x},{added.y}");

        Console.ReadKey();
    }
}