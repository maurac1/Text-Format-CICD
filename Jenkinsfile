pipeline
{
	agent
	{
		node
		{
			label 'WindowsSlave1'
		}
	}


	stages
	{
		stage('Preparation')
		{
			steps
			{
				checkout scm
			}
		}

		stage('Build')
		{
			steps
			{
				bat 'mingw32-make successful'
				bat 'mingw32-make unsuccessful'
				archiveArtifacts 'src/contacts.txt'
				
			}
		}

		stage('Unit Test')
		{
			steps
			{
				echo 'Unit Test'
			}
		}

		stage('Static Analysis')
		{
			parallel
			{
				stage('SonarQube')
				{
					
					
					steps
					{
						
						withSonarQubeEnv('CBE SonarQube Server')
						{
							withCredentials([string(credentialsId: 'Mauras-SonarQube', variable: 'SONAR_LOGIN')])
							{
								bat 'build-wrapper-win-x86-64.exe --out-dir sonar mingw32-make -j successful unsuccessful'
								bat 'sonar-scanner -Dsonar.login="%SONAR_LOGIN%"'
								
							}
						}
						echo 'SonarQube'
					}
					
				}

				stage('Fortify')
				{
					steps
					{
						echo 'Fortify'
					}
				}
			}
		}

		stage('Integration Test')
		{
			steps
			{
				echo 'Integration Test'
				dir('src')
				{
					bat 'robot ASSET'

					step([$class:'RobotPublisher', disableArchiveOutput: false, logFileName:'log.html', onlyCritical: false, otherFiles: "", outputFileName: 'output.xml', outputPath: '.', passThreshold: 100, reportFileName: 'report.html', unstableThreshold: 100])
					archiveArtifacts 'log.html'
					archiveArtifacts 'report.html'
				}
			}
		}

		stage('Quality Gate')
		{
			steps
			{
				echo 'Quality Gate'
			}
		}

		stage('Publish')
		{
			steps
			{
				echo 'Publish'
			}
		}
	}
}