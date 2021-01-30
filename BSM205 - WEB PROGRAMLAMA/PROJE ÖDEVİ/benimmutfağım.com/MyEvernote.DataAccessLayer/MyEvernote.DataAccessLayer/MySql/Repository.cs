using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Linq.Expressions;
using MyEvernote.Core.DataAccess;

namespace MyEvernote.DataAccessLayer.MySql
{
    public class Repository<T> : RepositoryBase, IDataAccess<T> where T : class
    {
        public int Delete(T obj)
        {
            throw new NotImplementedException();
        }

        public T Find(Expression<Func<T, bool>> where)
        {
            throw new NotImplementedException();
        }

        public int Insert(T obj)
        {
            throw new NotImplementedException();
        }

        public List<T> List()
        {
            throw new NotImplementedException();
        }

        public List<T> List(Expression<Func<T, bool>> where)
        {
            throw new NotImplementedException();
        }

        public IQueryable<T> ListQueryable()
        {
            throw new NotImplementedException();
        }

        public int Save()
        {
            throw new NotImplementedException();
        }

        public int Update(T obj)
        {
            throw new NotImplementedException();
        }
    }
}
