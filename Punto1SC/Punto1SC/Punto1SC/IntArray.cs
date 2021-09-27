using System;
using System.Collections.Generic;
using System.Text;

namespace Punto1SC
{
    class IntArray
    {
        int[] array;

        public IntArray(int size)//stack
        {
            array = new int[size];//heap
            for(int i = 0; i < size; i++)//stack
            {
                array[i] = i;
            }
        }

        public void PrintArray()
        {
            for (int i = 0; i < array.Length; i++)//stack
            {
                Console.WriteLine("array[{0}]: {1}",array[i], i);
            }
        }
    }
}
