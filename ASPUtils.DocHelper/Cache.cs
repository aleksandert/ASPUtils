using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ASPUtils
{
    /// <summary>
    /// Implements the cache for a application.
    /// </summary>
    public class Cache
    {
        /// <summary>
        /// Inserts an object into the <b>Cache</b>.
        /// </summary>
        /// <param name="key">The cache key used to reference the item.</param>
        /// <param name="value">The object to be inserted into the cache.</param>
        void Set(VARIANT key, VARIANT value)
        {
            return;
        }

        /// <summary>
        /// Inserts an object into the <b>Cache</b> with sliding expiration policy.
        /// </summary>
        /// <param name="key">The cache key used to reference the object.</param>
        /// <param name="value">The object to be inserted in the cache. </param>
        /// <param name="slidingExpiration">The interval (in seconds) between the time the inserted object is last accessed and the time at which that object expires.</param>
        void SetSliding(VARIANT key, VARIANT value, VARIANT slidingExpiration)
        {
            return;
        }

        /// <summary>
        /// Inserts an object into the <b>Cache</b> with absolute expiration policy.
        /// </summary>
        /// <param name="key">The cache key used to reference the object.</param>
        /// <param name="value">The object to be inserted in the cache. </param>
        /// <param name="absoluteExpiration">The time at which the inserted object expires and is removed from the cache.</param>
        void SetAbsolute(VARIANT key, VARIANT value, VARIANT expiration)
        {
            return;
        }

        /// <summary>
        /// Gets or sets cached item.
        /// </summary>
        /// <param name="key">The identifier for the cache item to get or set.</param>
        VARIANT this[VARIANT key]
        {
            get
            {
               return VARIANT.Dummy;
            }
            set
            {
                
            }
        }
        
        /// <summary>
        /// Returns the size in bytes of the cached object.
        /// </summary>
        /// <param name="key">The identifier for the cached item.</param>
        long GetSize(VARIANT key)
        {
            return 0;
        }

        /// <summary>
        /// Gets the number of items stored in the cache.
        /// </summary>
        long Count()
        {
            return 0;
        }

        /// <summary>
        /// Determines whether the <b>Cache</b> contains the specified key.
        /// </summary>
        /// <param name="Key">The key to locate in the Cache.</param>
        bool Exists(VARIANT Key)
        {
            return true;
        }

        /// <summary>
        /// Gets a collection containing the keys in the Cache.
        /// </summary>
        VARIANT Keys()
        {
            return VARIANT.Dummy;
        }

        /// <summary>
        ///	Returns the absolute expiration date for cached object.
        /// </summary>
        /// <param name="Key">The identifier for the cache item.</param>
        VARIANT Expires(VARIANT Key)
        {
            return VARIANT.Dummy;
        }

        /// <summary>
        /// Removes the specified item from the <b>Cache</b> object.
        /// </summary>
        /// <param name="Key">The identifier for the cache item.</param>
        void Remove(VARIANT Key)
        {
            return;
        }

        /// <summary>
        /// Removes all keys and values from the <b>Cache</b>.
        /// </summary>
        /// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
        void RemoveAll()
        {
            return;
        }

        /// <summary>
        /// Returns an enumeration interface for the Cache keys (for each support).
        /// </summary>
        IUnkown _NewEnum()
        {
            return IUnkown.Dummy;
        }

    }



    struct VARIANT
    {
        public static VARIANT Dummy;
    }



    struct IUnkown
    {
        public static IUnkown Dummy;
    }
}

