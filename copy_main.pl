#! /usr/bin/perl
use strict;

my $get_main_from_file = $ARGV[0];

open FH, "<$get_main_from_file" or die "$get_main_from_file not found";
local $/ = undef;
my $file_contents = <FH>;
close FH;

$file_contents =~ /(int\s+main.*?\{.*?return.*?\})/is or die "Could not find main contents";
my $main_contents = $1;
my $main_file = "main_caller.c";
my $main_file_header = $get_main_from_file;
$main_file_header =~ s/\.c$/\.h/;
my $std_includes = "#include<stdio.h>";
my $test_includes = "#include\"custom_number_operations.h\"";
open FH, ">$main_file" or die "Could not open $main_file for writing";
print FH "#include\"$main_file_header\"\n$test_includes\n$std_includes\n\n$main_contents";
close FH;
