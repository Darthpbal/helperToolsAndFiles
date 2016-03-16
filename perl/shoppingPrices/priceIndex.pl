#!/usr/bin/perl
use strict;                  #strict interpretation of code
use warnings FATAL=>qw(all); #Throw errors for marginal behavior
use Switch;

# add these to the program
# - budget settings for this shopping session
# - shopping list check to indicate being over budget
# - if over budget, show line items, subtotal, budget, and how much the subtotal is over the budget
# - create ability to redefine the quantities or remove line items based on name

my $total = 0;
my %prices;
my @shoppingList;

sub run {
	open(shList, ">shoppingList.txt") or die("could not open shopping list for writing");
	print("\nWhat are you thinking about buying? item followed by quantity\n\n");
	print shList ("product\t\tquantity\t\tlineTot\n");
	while (1) {
		my $product = <STDIN>;
		chomp($product);

		if($prices{$product}) {
			my $quantity = <STDIN>;
			chomp($quantity);
			print shList ($product . "\t\t" . $quantity . "\t\t" . $prices{$product} * $quantity . "\n");
			$total += $prices{$product} * $quantity;
		}
		else{
			if($product eq "exit") {
				my $result = "\n\nSubtotal = $total \n";
				print($result);
				print shList ($result);
				close(shList);
				die("killing program\n");
			}else{
				print("Add new entry? yes/else ");
				my $choice = <STDIN>;
				chomp($choice);
				if($choice eq "yes"){
					print("Whatis the unit price? ");
					my $price = <STDIN>;
					chomp($price);

					print("how many? ");
					my $quantity = <STDIN>;
					chomp($quantity);

					# save new product entry
					open(indxSrc, ">>index") or die("couldn't open index file");
					print indxSrc ($product . "," . $price . "\n");
					close(indxSrc);

					$prices{$product} = $price;
					print shList ($product . "\t\t" . $quantity . "\t\t" . $prices{$product} * $quantity . "\n");
					$total += $prices{$product} * $quantity;
				}
			}
		}
	}
}

# sub addProduct {
#
# }

sub printPrices {
	my $toggle = 1;
	open(outFile, ">options") or die("couldn't open output.txt for writing");
	print outFile ("\nExisting options are:\n\n");
	# sort(keys %prices);
	# my @sorted_keys = sort { $breakfast_hash{$a} cmp $breakfast_hash{$b} } keys %breakfast_hash;
	# foreach my $key (@sorted_keys) {
	#   print "$key likes $breakfast_hash{$key} for breakfast.\n";
	# }

	foreach my $key (%prices){
		($toggle)? print outFile ($key . "\n"): print "";
		$toggle = ! $toggle;
	}
	close(outFile);
}

sub constrPricesHash {
	while (my $line = <indexFile>) {
		chomp($line);
		my @tmp = split(",", $line);
		$prices{$tmp[0]} = $tmp[1];
	}
}


open(indexFile, "<index") or die("couldn't open index file");
&constrPricesHash();
close(indexFile);

open(modeFile, "<conf.txt") or die("couldn't open conf.txt");
my $mode = <modeFile>;
close(modeFile);
chomp($mode);
switch ($mode) {
	case "run"		{
		print "in run mode\n";
		&run();
	}
	case "display"	{
		print "in display mode\n";
		&printPrices();
	}
	else		{
		print "invalid configuration file\n";
	 }
}
