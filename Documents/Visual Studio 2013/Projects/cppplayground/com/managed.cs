using System.Runtime.InteropServices;


[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
[Guid("d2f20126-eb9a-4f5c-bc33-1f24dbc266a6")]
interface ILion
{
    [PreserveSig]void Roar();
    [PreserveSig]void Attack();
}

[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
 [Guid("699833cc-dcd6-4bea-a719-96423678ea51")]
interface ILion2
{
    //ILion
    [PreserveSig]void Roar();
    [PreserveSig]void Attack();

    //ILion2
    [PreserveSig]void Hunt();

}

class Application
{
    static void Main()
    {
        ILion lion = CreateLion();
        lion.Roar();
        lion.Attack();

        ILion2 lion2 = (ILion2)lion;
        lion2.Hunt();
    }
    [DllImport("library.dll", PreserveSig = false)]
    static extern ILion CreateLion();
}