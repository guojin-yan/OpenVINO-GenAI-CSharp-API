using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OpenVinoSharp.GenAI
{
    /// <summary>
    /// DisposableObject + IOvPtrHolder
    /// </summary>
    public abstract class DisposableOvObject : DisposableObject, IOvPtrHolder
    {
        /// <summary>
        /// Data pointer
        /// </summary>
        protected IntPtr ptr;

        /// <summary>
        /// Default constructor
        /// </summary>
        protected DisposableOvObject()
            : this(true)
        {
        }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="ptr"></param>
        protected DisposableOvObject(IntPtr ptr)
            : this(ptr, true)
        {
        }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="isEnabledDispose"></param>
        protected DisposableOvObject(bool isEnabledDispose)
            : this(IntPtr.Zero, isEnabledDispose)
        {
        }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="ptr"></param>
        /// <param name="isEnabledDispose"></param>
        protected DisposableOvObject(IntPtr ptr, bool isEnabledDispose)
            : base(isEnabledDispose)
        {
            this.ptr = ptr;
        }

        /// <summary>
        /// releases unmanaged resources
        /// </summary>
        protected override void DisposeUnmanaged()
        {
            ptr = IntPtr.Zero;
            base.DisposeUnmanaged();
        }

        /// <summary>
        /// Native pointer of OpenVINO GenAI structure
        /// </summary>
        public IntPtr OvPtr
        {
            get
            {
                ThrowIfDisposed();
                return ptr;
            }
        }
    }
}
