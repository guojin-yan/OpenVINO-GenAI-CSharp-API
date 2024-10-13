using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OpenVinoSharp.GenAI.Internal
{
    public static partial class NativeMethods
    {
        [Pure, DllImport(dllExtern, EntryPoint = "ov_genai_llm_sizeof",
            CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public extern static ExceptionStatus ov_genai_llm_sizeof();
    }
}
