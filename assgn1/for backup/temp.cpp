				for(map<set<int>,int>::iterator itt = final_mapping.begin();itt!=final_mapping.end();itt++){
					if((itt->first).find(i)!=(itt->first).end()){
						aisehi.clear();
						aisehi = itt->first;
						aisehi.insert(i);	
						cout<<" i is done "	<< i<<endl;
						final_mapping[aisehi] = itt->second;
						to_erase = final_mapping.find(itt->first); //http://stackoverflow.com/questions/10038985/remove-a-key-from-a-c-map
						final_mapping.erase(to_erase); // !!!!!!!!!!!!!!!!BEWARE!!!!!!!NEVER EVER ERASE DIRECTLY IN MAP OTHERWISE ENTRY AFTER ERASING ALSO BE REMOVED!
						mila_kya = true;
						break;
					}
				}
				if(mila_kya == false){
					aisehi.clear();
					aisehi.insert(i);
					final_mapping[aisehi] = curCount++;
				}


				