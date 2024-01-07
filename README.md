<h1>InvertedSearch</h1>
<h3>Written by: MD IRSHAN NAZIR</h3>
<h3 align="left">Connect with me:</h3>
<p align="left">
<a href="https://www.linkedin.com/in/irshan127/" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="https://www.linkedin.com/in/irshan127/" height="30" width="40" /></a> <a href="https://twitter.com/Irshan_127" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="https://twitter.com/irshan_127" height="35" width="40" />
</p>

<h2>Introduction:</h2>
<p>An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its locations in a database file, or in a document or a set of documents. The purpose of an inverted index is to allow fast full text searches, at the cost of increased processing when a document is added to the database. The inverted file may be the database file itself, rather than its index. It is the most popular data structure used in document retrieval systems, used on a large scale for example in search engines.</p>

<h2>Requirement Specification</h2>
<p>Implementing this search program mainly consists two important functions.</p>
<ol>
  <li>Indexing</li>
  <li>Querying/Searching</li>
</ol>

<h3>Indexing:</h3>
<p>By Indexing, we are creating a database file which contains the index of all words. So this can be termed as Database Creation also. All the files whose index are to be created are selected and inputed to this function. All the files are parsed and words are separated and indexed. They are arranged in sorted order. For this a sorted Linked List or Hashing is used which will store the words and the related file details. The index thus created is then stored in the file as database. This file is later used in Querying. While the files are removed or added this index file is updated.</p>

<h3>Searching:</h3>
<p>Once the Indexing is over we have the Querying or Searching. The text to be searched is inputed which is parsed into words and those words are searched in the index file. To avoid the overhead of reading the file again, the file is converted back to a linkedList or hashing program, in which the words are searched. The information about the files which contain the words are collected. The ones with more matches are filtered and produced as the result.</p>

<h2>Prerequisite:</h2>
<ul>
  <li>Hashing</li>
  <li>Single linked list</li>
</ul>

<p>To create executable file type "make"</p>

<p>and</p>

<p>Then to run the program type "main.exe" and "file names" exist in that folder example "main.exe f1.txt f2.txt"</p>

<h2>References</h2>
<ol>
  <li><a href="https://en.wikipedia.org/wiki/Inverted_index">https://en.wikipedia.org/wiki/Inverted_index</a></li>
  <li><a href="https://nlp.stanford.edu/IR-book/html/htmledition/a-first-take-at-building-an-inverted-index-1.html">https://nlp.stanford.edu/IR-book/html/htmledition/a-first-take-at-building-an-inverted-index-1.html</a></li>
  <li><a href="https://www.ijcsi.org/papers/IJCSI-8-4-1-384-392.pdf">https://www.ijcsi.org/papers/IJCSI-8-4-1-384-392.pdf</a></li>
  <li><a href="https://www.elastic.co/guide/en/elasticsearch/guide/current/inverted-index.html">https://www.elastic.co/guide/en/elasticsearch/guide/current/inverted-index.html</a></li>
  <li><a href="https://www.quora.com/Information-Retrieval-What-is-inverted-index">https://www.quora.com/Information-Retrieval-What-is-inverted-index</a></li>
</ol>
