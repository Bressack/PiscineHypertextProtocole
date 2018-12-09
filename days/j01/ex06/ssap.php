<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssap.php                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:55:25 by tarchen           #+#    #+#             */
/*   Updated: 2018/12/07 12:09:04 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

function ft_split($line)
{
	$split = preg_split("/[\s]+/", rtrim($line));
	if ($line != NULL)
		sort($split);
	return $split;
}

$ret = array();
foreach ($argv as $iargv)
{
	if ($iargv != $argv[0])
	{
		$tab = ft_split($iargv);
		$ret = array_merge($ret, $tab);
	}
}
sort($ret);
foreach ($ret as $iret) {
	echo $iret . "\n";
}

?>
