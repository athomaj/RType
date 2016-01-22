/*
** circular_buffer.c for  in /home/athoma_j/rendu/Tek2/PSU_2014_zappy/server
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Fri Jun 26 17:06:48 2015 julien athomas
// Last update Sun Jun 28 14:25:40 2015 julien athomas
*/

#include "circular_buffer.hh"

CBuf::CBuf()
{
  memset(buf, 0, BUF_SIZE);
  idx = 0;
  len = 0;
}

CBuf::~CBuf()
{

}

std::vector<unsigned char>	CBuf::getData()
{
  int	i;
  int	j;
    std::vector<unsigned char> newBuf;

  if (len < 12)
    return (newBuf);

    i = idx;
    unsigned int *size;
  //  unsigned int *magic;

  //  magic = reinterpret_cast<unsigned int *>(&buf[i]);
    size = reinterpret_cast<unsigned int *>(&buf[i + 4]);
//    std::cout << *magic << std::endl;
    if (*size > 1000)
    {
        memset(buf, 0, BUF_SIZE);
        idx = 0;
        len = 0;
        return newBuf;
    }
    if (*size > len)
        return (newBuf);
  j = -1;
  while (++j < *size)
    {
      newBuf.push_back(buf[i]);
      i = (i + 1) % BUF_SIZE;
    }
  buf[i] = 0;
    idx += j;
  idx %= BUF_SIZE;
  len -= (j);
//    std::cout << "size used:" << j << "size left:" << len << std::endl;
  return (newBuf);
}

void		CBuf::addData(unsigned char *add, int size)
{
  int	i;
  int	j;

  i = (idx + len) % BUF_SIZE;
  len += size;
  j = -1;
  while (++j < size)
    {
      buf[i % BUF_SIZE] = add[j];
      ++i;
    }
}

void		CBuf::displayData()
{
}

bool CBuf::isDataLeft() const
{
    if (len)
        return true;
    return false;
}