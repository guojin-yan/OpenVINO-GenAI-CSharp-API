using OpenVinoSharp.GenAI.Internal;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OpenVinoSharp.GenAI.Internal
{
    /// <summary>
    /// The default exception to be thrown by OpenVINO
    /// </summary>
    [Serializable]
    // ReSharper disable once InconsistentNaming
    public class OVException : Exception
    {
        /// <summary>
        /// The numeric code for error status
        /// </summary>
        public ExceptionStatus Status { get; set; }


        /// <summary>
        /// A description of the error
        /// </summary>
        public string ErrMsg { get; set; }



        /// <inheritdoc />
        /// <param name="message"></param>
        public OVException(string message)
            : base(message)
        {
        }

        /// <inheritdoc />
        /// <param name="message"></param>
        /// <param name="innerException"></param>
        public OVException(string message, Exception innerException)
            : base(message, innerException)
        {
        }

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="status">The numeric code for error status</param>
        /// <param name="errMsg">A description of the error</param>
        public OVException(ExceptionStatus status, string errMsg)
            : base(errMsg)
        {
            this.Status = status;
            this.ErrMsg = errMsg;
        }

    }
}
