using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OpenVinoSharp.GenAI
{
    /// <summary>
    /// Represents a OpenVINO GenAI based class which has a native pointer. 
    /// </summary>
    public interface IOvPtrHolder
    {
        /// <summary>
        /// Unmanaged TensorRT data pointer
        /// </summary>
        IntPtr OvPtr { get; }
    }
}
