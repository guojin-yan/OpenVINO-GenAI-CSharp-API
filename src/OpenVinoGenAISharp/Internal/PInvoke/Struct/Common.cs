using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OpenVinoSharp.GenAI.Internal
{
    public static class StructCommon
    {

        public static StringArray StringArrayToStruct(string[] strs)
        {
            StringArray stringArray = new StringArray();
            ulong size = (ulong)strs.Length;
            IntPtr[] str_ptrs = new IntPtr[strs.Length];
            for (int i = 0; i < strs.Length; ++i)
            {
                str_ptrs[i] = Marshal.StringToHGlobalAnsi(strs[i]);
            }

            IntPtr data = Marshal.AllocHGlobal(IntPtr.Size * strs.Length);
            Marshal.Copy(str_ptrs, 0, data, strs.Length);
            return new StringArray { Data = data, Size = size };
        }
    }
}
