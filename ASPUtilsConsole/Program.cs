using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Enyim.Caching;
using Enyim.Caching.Memcached;

namespace ASPUtilsConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            MemcachedClient client = new MemcachedClient();

            

            client.Store(StoreMode.Set, "test", 10, TimeSpan.FromMinutes(20));

            client.Cas(StoreMode.Set, "t1", 1, TimeSpan.FromMinutes(20), 1);

            int val = client.Get<int>("test");

            int v = client.Get<int>("t1");

            Console.WriteLine(val);
            Console.WriteLine(v);

            Console.ReadLine();
        }
    }
}
