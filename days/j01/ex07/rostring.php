<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.php                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:08:52 by tarchen           #+#    #+#             */
/*   Updated: 2018/12/07 16:35:08 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


$split = explode(' ', trim(preg_replace('/\s{2,}/', ' ', $argv[1])));

$split = array_reverse($split);
$tmp = array();
$tmp[0] = array_shift($split);
$split = array_reverse($split);
$ret = array_merge($tmp, $split);
foreach ($ret as $s) {
	echo $s . " ";
}
echo "\n";
?>