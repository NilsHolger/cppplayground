using System.Runtime.InteropServices;

class Application
{
	static void Main()
	{
		LionRoar();		
	}
	
	[DllImport("library.dll")]
	static extern void LionRoar();

}