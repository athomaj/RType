/*
** circular_buffer.h for  in /home/athoma_j/rendu/Tek2/PSU_2014_zappy/server
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Fri Jun 26 17:07:02 2015 julien athomas
// Last update Fri Jul 10 00:19:51 2015 julien athomas
*/

#ifndef CBUFFER_H_
# define CBUFFER_H_

#include <vector>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <iostream>

# define BUF_SIZE 30000

class	CBuf
{
 public:
  CBuf();
  ~CBuf();
    std::vector<unsigned char>	getData();
  void		addData(unsigned char *, int);
  void		displayData();
    bool isDataLeft() const;
 private:
  unsigned char		buf[BUF_SIZE];
  int		idx;
  int		len;
};

#endif
