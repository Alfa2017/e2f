using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

using System.Collections;

namespace FlyToElephant
{
  public class Algo
  {
    [DllImport("kernel32.dll")]
    static extern uint GetTickCount();

    public Algo()
    {
    }

    public void run()
    {
      long start = GetTickCount();
      String[] dict = "КОТ ТОН НОТА КОТЫ РОТ РОТА ТОТ".Split(' ');

      string source = "КОТ";
      string target = "ТОН";

      List<string> dictionary = new List<string>();
      foreach(var it in dict) {
        if( source.Length == it.Length ) {
          dictionary.Add(it);
        }
      }

      Queue<Word> intermediateWords = new Queue<Word>();

      Word word = new Word(source);
      intermediateWords.Enqueue(word);
      while( intermediateWords.Count > 0 ) {
        word = intermediateWords.Dequeue();

        if( word.m_word == target ) {
          dictionary.Clear();
          intermediateWords.Clear();
          break;
        }

        for(int i = 0; i < dictionary.Count; ++i) {
          if( dictionary[i] == null ) continue;
          var diff = word.diffFromWord(dictionary[i]);
	  if (diff == 1) {
            var w1 = new Word(dictionary[i]);
            w1.prev = word;
            intermediateWords.Enqueue(w1);
            dictionary[i] = null;
            continue;
          }
        }
      }

      word.print();
    }
  }

  internal class Word
  {
    internal string m_word;
    internal Word m_prev = null;

    internal Word(string from)
    {
      m_word = from;
    }

    internal int diffFromWord(string word)
    {
      if (m_word == word) {
        return 0;
      }

      if (m_word.Length != word.Length) {
        return Math.Max(m_word.Length, word.Length);
      }

      int diffChars = 0;
      for (int i = 0; i != m_word.Length; ++i) {
        if (m_word[i] != word[i]) {
          ++diffChars;
        }
        if( diffChars > 1 ) break;
      }
      return diffChars;
    }
    internal void setPrev( Word word)
    {
      m_prev = word;
    }

    internal string value { get { return m_word; } }
    internal Word prev { 
      get { return m_prev; }
      set { m_prev = value; }
    }

    override public string ToString()
    {
      return string.Format("{0}<-{1}", m_word, (m_prev == null ? "null" : m_prev.value));
    }
    
    internal void print()
    {
      Word word = this;     
      List<string> reverseResult = new List<string>();
      while( word != null ) {
        reverseResult.Insert(0, word.value);
        word = word.prev;
      }
      foreach( var it in reverseResult ) {
        Console.WriteLine(it);
      }
    }
  }
}
