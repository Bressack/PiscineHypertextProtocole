<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.php                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:12:49 by tarchen           #+#    #+#             */
/*   Updated: 2018/12/08 13:34:01 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include("./ft_is_sort.php");

$tab = array(	'Lorem',
				'ipsum',
				'dolor',
				'sit',
				'amet',
				'consectetur',
				'adipisicing',
				'elit',
				'sed',
				'aaa',
				'abb',
				'bba',
				'abc',
				'aba',
				'bbb',
				'ccc',
				'cba',
				'bac',
				'aac');
print_r($tab);
if(ft_is_sort($tab))
	echo "ok :)\n";
else
	echo "ko :(\n";

sort($tab);

print_r($tab);
if(ft_is_sort($tab))
	echo "ok :)\n";
else
	echo "ko :(\n";

?>